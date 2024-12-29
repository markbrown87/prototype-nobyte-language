#include "parser.hpp"
#include "token_struct.hpp"
#include "ast.hpp"

#include <iostream>

using namespace PSR_NS;

Parser::Parser(std::unique_ptr<LXR_NS::Lexer> lex) : p_lexer(std::move(lex)) {}

Parser::~Parser(){
  p_lexer.reset();
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
      if(p_lexer->getCurrentToken().strValue == "print")
        expression();
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

}

auto Parser::identifier() -> void{

}

auto Parser::expression() -> void{

}

auto Parser::numeral() -> void{

}

auto Parser::literal(const LXR_NS::Token& token) -> std::unique_ptr<AST_NS::LiteralNode>{

  return {};
}

// auto Parser::analysis(const std::vector<LXR_NS::Token> &tokens) const noexcept
//     -> bool {
//   return helper.isExpression(tokens);
// }