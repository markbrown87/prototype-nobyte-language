#ifndef PARSER_HPP
#define PARSER_HPP

#include "lexer.hpp"

#include <memory>

namespace AST_NS{
class ExpressionInterface;
class LiteralNode;
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

  auto expression() -> void;

  auto numeral() -> void;

  auto literal(const LXR_NS::Token& token) -> std::unique_ptr<AST_NS::LiteralNode>;

  std::unique_ptr<LXR_NS::Lexer> p_lexer{};
  std::unique_ptr<AST_NS::ExpressionInterface> p_ast{};
};
} // namespace PSR_NS

#endif