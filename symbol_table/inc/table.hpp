#ifndef TABLE_HPP
#define TABLE_HPP

#include <string>
#include <vector>

// Symbol Table Namespace0
namespace STB_NS{

    class SymbolTable{
        public:
        SymbolTable() = default;

        auto insert(std::string symbol) const -> void;

        auto print_table() const -> void;

        private:
        std::vector<std::string> m_symbols {};
    };
}

#endif // TABLE_HPP