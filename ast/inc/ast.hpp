#ifndef AST_HPP
#define AST_HPP

#include <string>

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
};

class NumeralNode : public ExpressionInterface{
  int m_value;
  public:
  NumeralNode(const int& value);
};
} // namespace AST_NS

#endif