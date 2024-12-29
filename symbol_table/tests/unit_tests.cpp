#include "table.hpp"

#include <gtest/gtest.h>

#include <string>

using namespace STB_NS;

TEST(SymbolTable_Class, insert_lookup) { 
    SymbolTable st;

    Symbol s{"x", "5"};
    std::string ns = "global";

    st.insert(ns, s);

    EXPECT_EQ(st.lookup(ns, s.key).value, s.value);
}