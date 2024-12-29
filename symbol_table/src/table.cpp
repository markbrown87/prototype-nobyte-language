#include "table.hpp"

#include <iostream>

using namespace STB_NS;

auto SymbolTable::insert(const std::string& name_space, const Symbol& symbol) -> void {
  //TODO handle collisions
  std::cout << "Inserting into map: '" << name_space + "::" + symbol.key  << "' value: " << symbol.value << std::endl;
  m_symbols.emplace(name_space + "::" + symbol.key, symbol);
}

auto SymbolTable::lookup(const std::string& name_space, const std::string& variable) const -> const Symbol&{
  // TODO look up data
  return m_symbols.at(name_space + "::" + variable);
} 

auto SymbolTable::print_table() const -> void {
  //TODO Print better?
  for(auto pair : m_symbols){
    std::cout << "Namespace: " << pair.first << ", value: " << pair.second.value << std::endl;
  }
}