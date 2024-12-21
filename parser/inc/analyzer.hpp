#ifndef ANALYZES_HPP
#define ANALYZES_HPP

#include <string>
#include <vector>

namespace LXR_NS {
struct Token;
}

namespace PSR_NS {
class Anaylzer {
public:
  Anaylzer() = default;

  // <identifier> "=" <expression>
  [[nodiscard]] auto
  isStatement(const std::vector<LXR_NS::Token> &) const noexcept -> bool;

  // <factor> | <factor> "+" <factor> | <factor> "-" <factor> | <factor> "*"
  // <factor> | <factor> "/" <factor>
  [[nodiscard]] auto
  isExpression(const std::vector<LXR_NS::Token> &) const noexcept -> bool;

  // <number> | "(" <expression> ")"
  [[nodiscard]] auto isFactor(const std::string &) const noexcept -> bool;

  // [0-9]+
  [[nodiscard]] auto isNumber(const std::string &) const noexcept -> bool;

  // [a-zA-Z]+
  [[nodiscard]] auto isIdentifer(const std::string &) const noexcept -> bool;
};
} // namespace PSR_NS

#endif // ANALYZES_HPP