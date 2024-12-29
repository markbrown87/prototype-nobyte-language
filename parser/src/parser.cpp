#include "parser.hpp"
#include "table.hpp"
#include "token_struct.hpp"
#include "analyzer.hpp"
#include "ast.hpp"

#include <iostream>
#include <memory>
#include <stdexcept>

using namespace PSR_NS;

Parser::Parser(std::unique_ptr<LXR_NS::Lexer> lex) : p_lexer(std::move(lex)), p_symbolTable(std::make_unique<STB_NS::SymbolTable>()){}

Parser::~Parser(){
  p_lexer.reset();
  p_symbolTable.reset();
}

Parser::Parser(Parser&& other) : p_lexer(std::move(other.p_lexer)){}

auto Parser::operator=(Parser&& other) -> Parser& {
  p_lexer = std::move(other.p_lexer);
  return *this;
}

auto Parser::process() -> int {
  std::cout << "Progam Processing Starting..." << std::endl;
  while (true) {
    switch (p_lexer->getNextToken().type) {
    case LXR_NS::TokenType::IDENTIFIER:
      std::cout << "Processing Identifier: " << p_lexer->getCurrentToken().strValue
                << std::endl;
      identifier();
      break;
    case LXR_NS::TokenType::KEYWORD:
      std::cout << "Processing Keyword: " << p_lexer->getCurrentToken().strValue
                << std::endl;
      if(p_lexer->getCurrentToken().strValue == "print"){
        auto symbol = p_symbolTable->lookup("global", p_lexer->getNextToken().strValue);

        std::cout << "Printing '" << symbol.key << "': '" << symbol.value << "'" << std::endl;
      }

        //expression();
      break;
    case LXR_NS::TokenType::COMMENT:
      std::cout << "Processing Comment: " << p_lexer->getCurrentToken().strValue
                << std::endl;
      break;
    case LXR_NS::TokenType::EoF:
      std::cout << "End of File and processing." << std::endl;
      return 0;
    default:
      std::cout << "Processing Global Statement: " << p_lexer->getCurrentToken().strValue
          << std::endl;
      statement();
      break;
    }
  }

  return 1;
}

auto Parser::statement() -> void{
  auto curToken = p_lexer->getCurrentToken();
  auto nexToken = p_lexer->getNextToken();

  if(nexToken.strValue == "="){
    auto astLiteral = literal();
    // eat '='
    p_lexer->getNextToken();
    auto astNum = numeral();
    
    p_symbolTable->insert("global", {astLiteral->getValue(), std::to_string(astNum->getValue())});
  } else {
    throw std::runtime_error("Malformed file");
  }
}

auto Parser::identifier() -> void{
  std::cout << "Grabbing curret token.." << std::endl;
  auto curToken = p_lexer->getCurrentToken();

  auto astLiteral = literal();
  std::cout << "Grabbing next token.." << std::endl;
  auto nexToken = p_lexer->getNextToken();

  if(nexToken.strValue == "="){
    std::cout << "Eating token..." << std::endl;
    // eat '='
    p_lexer->getNextToken();
    std::cout << "Grabbing numeral..." << std::endl;
    auto astNum = numeral();
    std::cout << "Inserting into Symbol Table..." << std::endl;

    auto litValue = astLiteral->getValue();
    auto numValue = astNum->getValue();
    std::cout << "Literal: " << litValue << std::endl;
    std::cout << "numValue: " << std::to_string(astNum->getValue()) << std::endl;
    p_symbolTable->insert("global", {litValue, std::to_string(numValue)});
  } else {
    throw std::runtime_error("Malformed file");
  }
}

auto Parser::expression() -> std::unique_ptr<AST_NS::ExpressionInterface>{
  auto curToken = p_lexer->getCurrentToken();
  auto nexToken = p_lexer->getNextToken();

  if(nexToken.strValue == "+" || nexToken.strValue == "-" || nexToken.strValue == "*" || nexToken.strValue == "/" ){
    auto lhs = numeral();
    auto op = nexToken.strValue;
    auto rhs = expression();

    // This is REALLY REALLY bad... fix it later, okay?
    return std::make_unique<AST_NS::ExpressionNode>(op[0], std::move(lhs), std::move(rhs));
  }

  if(m_analyzer.isNumber(curToken.strValue)){
    return numeral();
  }

  throw std::runtime_error("Malformed file.");
}

auto Parser::numeral() -> std::unique_ptr<AST_NS::NumeralNode>{
  return std::make_unique<AST_NS::NumeralNode>(stoi(p_lexer->getCurrentToken().strValue));
}

auto Parser::literal() -> std::unique_ptr<AST_NS::LiteralNode>{
  return std::make_unique<AST_NS::LiteralNode>(p_lexer->getCurrentToken().strValue);
}

// auto Parser::analysis(const std::vector<LXR_NS::Token> &tokens) const noexcept
//     -> bool {
//   return helper.isExpression(tokens);
// }