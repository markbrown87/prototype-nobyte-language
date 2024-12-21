#include "analyzer.hpp"
#include "token_struct.hpp"

#include <iostream>
#include <regex>

using namespace PSR_NS;

auto Anaylzer::isStatement(
    const std::vector<LXR_NS::Token> &tokens) const noexcept -> bool {

  return false;
}

auto Anaylzer::isExpression(
    const std::vector<LXR_NS::Token> &tokens) const noexcept -> bool {
  if (tokens.size() == 0)
    return false;
  if (tokens.size() == 1)
    return isFactor(tokens[0].strValue);
  if (tokens.size() == 2)
    return false;
  if (tokens.size() == 3)
    return (tokens[1].strValue == "-" || tokens[1].strValue == "+") &&
           isFactor(tokens[0].strValue) && isFactor(tokens[2].strValue);

  return isFactor(tokens[0].strValue) &&
         isExpression({tokens.begin() + 2, tokens.end()});
}

auto Anaylzer::isFactor(const std::string &str) const noexcept -> bool {
  if (isNumber(str)) {
    std::cout << "Found a Number: " << str << std::endl;
    return true;
  } else {
    std::cout << "Did not find a number: " << str << std::endl;
    return false;
  }
}

auto Anaylzer::isNumber(const std::string &str) const noexcept -> bool {
  std::regex numberRegex("[0-9]+$");
  return std::regex_match(str, numberRegex);
}

auto Anaylzer::isIdentifer(const std::string &str) const noexcept -> bool {
  std::regex identifierRegex("[a-zA-Z]+$");
  return std::regex_match(str, identifierRegex);
}
