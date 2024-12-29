#ifndef TABLE_HPP
#define TABLE_HPP

#include <string>
#include <map>

// Symbol Table Namespace0
namespace STB_NS {

struct Symbol{
  std::string key{""};
  std::string value{""};
};

class SymbolTable {
public:
  SymbolTable() = default;

  auto insert(const std::string&, const Symbol&) -> void;

  auto lookup(const std::string&, const std::string&) const -> const Symbol&; 

  auto print_table() const -> void;

private:
  // namespace,symbol
  std::map<std::string, Symbol> m_symbols{};
};
} // namespace STB_NS

#endif // TABLE_HPP