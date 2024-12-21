#ifndef PARSER_HPP
#define PARSER_HPP

#include "analyzer.hpp"

#include <vector>

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
  Parser() = default;

  /*
  Cycle through token list to check for grammar
  */
  [[nodiscard]] auto analysis(const std::vector<LXR_NS::Token> &) const noexcept
      -> bool;

private:
  Anaylzer helper;
};
} // namespace PSR_NS

#endif