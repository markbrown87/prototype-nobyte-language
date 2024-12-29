#include "ast.hpp"

using namespace AST_NS;

LiteralNode::LiteralNode(const std::string& name) : m_name(name){}

NumeralNode::NumeralNode(const int& value) : m_value(value){}