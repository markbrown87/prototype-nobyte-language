#ifndef TOKEN_STRUCT_HPP
#define TOKEN_STRUCT_HPP

#include "token_type.hpp"

#include <string>

namespace LXR_NS {
/*
Token Data structure
*/
struct Token {
  std::string strValue;
  TokenType type;
};
} // namespace LXR_NS

#endif