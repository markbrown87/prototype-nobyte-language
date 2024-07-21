#include "lexer.hpp"
#include "char_type.hpp"

#include <cctype>
#include <sstream>

using namespace LXR_NS;

const std::vector<Token> Lexer::lex(std::stringstream &stream) const noexcept {
  std::vector<Token> tokens;

  char tmp_value;
  while (stream >> std::noskipws >> tmp_value) {
    if (std::isdigit(tmp_value)) {
      tokens.push_back({{tmp_value}, TokenType::LITERAL});
    } else if (UTILS_NS::isOperator(tmp_value)) {
      tokens.push_back({{tmp_value}, TokenType::OPERATOR});
    } else if (std::isblank(tmp_value)) {
      tokens.push_back({{tmp_value}, TokenType::WHITESPACE});
    }
  }

  return tokens;
}