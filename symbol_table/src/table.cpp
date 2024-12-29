#include "table.hpp"

using namespace STB_NS;

auto SymbolTable::insert(const std::string& name_space, const Symbol& symbol) -> void {
  //TODO handle collitions
  m_symbols.emplace(name_space + "::" + symbol.key, symbol);
}

auto SymbolTable::lookup(const std::string& name_space, const std::string& variable) const -> const Symbol&{
  // TODO look up data
  return m_symbols.at(name_space + "::" + variable);
} 

auto SymbolTable::print_table() const -> void {
  // TODO print the table in a format
}