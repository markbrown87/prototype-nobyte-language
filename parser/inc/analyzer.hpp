#ifndef ANALYZES_HPP
#define ANALYZES_HPP

#include <string>
#include <vector>

namespace LXR_NS{
    struct Token;
}

namespace PSR_NS{
    class Anaylzer{
        public:
        Anaylzer() = default;

        // <identifier> "=" <expression>
        auto isStatement(const std::vector<LXR_NS::Token>&) const noexcept -> bool;

        // <factor> | <factor> "+" <factor> | <factor> "-" <factor> | <factor> "*" <factor> | <factor> "/" <factor>
        auto isExpression(const std::vector<LXR_NS::Token>&) const noexcept -> bool;

        // <number> | "(" <expression> ")"
        auto isFactor(const std::string&) const noexcept -> bool;

        // [0-9]+
        auto isNumber(const std::string&) const noexcept -> bool;

        // [a-zA-Z]+
        auto isIdentifer(const std::string&) const noexcept -> bool;
    };
}

#endif // ANALYZES_HPP