#include "char_type.hpp"

#include <regex>

bool UTILS_NS::isOperator(char value) noexcept {
  return std::regex_match(std::string{value}, std::regex("[+-]"));
}