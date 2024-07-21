#include "char_type.hpp"

#include <gtest/gtest.h>

using namespace UTILS_NS;

TEST(UTIL_Functions, isOperator_plus) {
  char *value = new char('+');

  EXPECT_TRUE(isOperator(*value));

  delete value;
}

TEST(UTIL_Functions, isOperator_minus) {
  char *value = new char('-');

  EXPECT_TRUE(isOperator(*value));

  delete value;
}

TEST(UTIL_Functions, not_isOperator_numeric) {
  char *value = new char('0');

  EXPECT_FALSE(isOperator(*value));

  delete value;
}

TEST(UTIL_Functions, not_isOperator_alpha) {
  char *value = new char('a');

  EXPECT_FALSE(isOperator(*value));

  delete value;
}