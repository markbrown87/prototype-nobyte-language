#ifndef AST_HPP
#define AST_HPP

#include <string>
#include <memory>

// Namespace for AST
namespace AST_NS {
/*
Abstract Syntax Tree implementation
*/
class ExpressionInterface {
public:
  ExpressionInterface() = default;
};

class LiteralNode : public ExpressionInterface{
  std::string m_name;
  public:
  LiteralNode(const std::string& name);
  auto getValue() -> const std::string& {
    return m_name;
  }
};

class NumeralNode : public ExpressionInterface{
  int m_value;
  public:
  NumeralNode(const int& value);
  auto getValue() -> const int& {
    return m_value;
  }
};

class ExpressionNode : public ExpressionInterface{
  char m_op;
  std::unique_ptr<ExpressionInterface> m_lhs, m_rhs;

  public:
  ExpressionNode(char op, std::unique_ptr<ExpressionInterface> lhs, std::unique_ptr<ExpressionInterface> rhs) : m_op(op), m_lhs(std::move(lhs)), m_rhs(std::move(rhs)) {}  
};
} // namespace AST_NS

#endif