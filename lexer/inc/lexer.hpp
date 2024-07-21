#ifndef LEXER_HPP
#define LEXER_HPP

#include "token_struct.hpp"

#include <sstream>
#include <vector>

// Namespace for Lexer
namespace LXR_NS {
/*
Lexer class that parses and creates an array of tokens
*/
class Lexer {
public:
  Lexer() = default;

  /*
  Parses the line and returns an array of tokens
  */
  auto lex(std::stringstream &stream) const noexcept
      -> const std::vector<Token>;
};
} // namespace LXR_NS

#endif