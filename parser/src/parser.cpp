#include "parser.hpp"
#include "token_struct.hpp"

using namespace PSR_NS;

auto Parser::analysis(const std::vector<LXR_NS::Token> &tokens) const noexcept
    -> bool {
  return helper.isExpression(tokens);
}