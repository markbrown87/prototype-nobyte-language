#ifndef PARSER_HPP
#define PARSER_HPP

#include "analyzer.hpp"
#include "ast.hpp"
#include "lexer.hpp"
#include "table.hpp"

#include <memory>

namespace AST_NS{
class ExpressionInterface;
class LiteralNode;
class NumeralNode;
}

namespace LXR_NS {
struct Token;
}

// Namespace for Parser
namespace PSR_NS {
/*
Parser class that analyzes the stream of tokens to determine the grammatical
structure of the code and creates the AST.
*/
class Parser {
public:
  Parser() = delete;
  Parser(const Parser&) = delete;
  auto operator=(const Parser&) -> Parser& = delete;
  Parser(std::unique_ptr<LXR_NS::Lexer>);
  ~Parser();
  Parser(Parser&&);
  auto operator=(Parser&&) -> Parser&;

  auto process() -> int;

  private:

  auto statement() -> void;

  auto identifier() -> void;

  auto expression() -> std::unique_ptr<AST_NS::ExpressionInterface>;

  auto numeral() -> std::unique_ptr<AST_NS::NumeralNode>;

  auto literal() -> std::unique_ptr<AST_NS::LiteralNode>;

  std::unique_ptr<LXR_NS::Lexer> p_lexer{};
  std::unique_ptr<AST_NS::ExpressionInterface> p_ast{};
  std::unique_ptr<STB_NS::SymbolTable> p_symbolTable{};
  Anaylzer m_analyzer;
};
} // namespace PSR_NS

#endif