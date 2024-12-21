#include "analyzer.hpp"
#include "parser.hpp"
#include "token_struct.hpp"
#include "token_type.hpp"

#include <gtest/gtest.h>

using namespace PSR_NS;
using namespace LXR_NS;

TEST(Analyzer_Class, isIdentifer) {
  std::string trueVar = "someVariable";
  std::string falseVar = "some3234Variable";
  Anaylzer a;

  EXPECT_TRUE(a.isIdentifer(trueVar));
  EXPECT_FALSE(a.isIdentifer(falseVar));
}

TEST(Analyzer_Class, isNumber) {
  std::string trueVar = "14";
  std::string falseVar = "b12";
  Anaylzer a;

  EXPECT_TRUE(a.isNumber(trueVar));
  EXPECT_FALSE(a.isNumber(falseVar));
}

TEST(Analyzer_Class, isFactor) {
  std::string trueVar = "14";
  std::string falseVar = "b12";
  Anaylzer a;

  EXPECT_TRUE(a.isFactor(trueVar));
  EXPECT_FALSE(a.isFactor(falseVar));
}

TEST(Analyzer_Class, isExpression) {
  LXR_NS::Token lhs{"2", TokenType::LITERAL};
  LXR_NS::Token plusOp{"+", TokenType::OPERATOR};
  LXR_NS::Token minOp{"-", TokenType::OPERATOR};
  LXR_NS::Token divOp{"/", TokenType::OPERATOR};
  LXR_NS::Token rhs{"3", TokenType::LITERAL};
  std::vector<Token> truePlusTokens{lhs, plusOp, rhs};
  std::vector<Token> trueMinusTokens{lhs, minOp, rhs};
  std::vector<Token> trueLongTokens{lhs, minOp, rhs, plusOp, rhs};
  std::vector<Token> falseTokens{lhs, minOp};
  std::vector<Token> falseDivideTokens{lhs, divOp, rhs};
  std::vector<Token> falseLongTokens{lhs, minOp, rhs, plusOp, rhs, divOp};
  Anaylzer a;

  EXPECT_TRUE(a.isExpression(truePlusTokens));
  EXPECT_TRUE(a.isExpression(trueMinusTokens));
  EXPECT_TRUE(a.isExpression(trueLongTokens));
  EXPECT_FALSE(a.isExpression(falseTokens));
  EXPECT_FALSE(a.isExpression(falseDivideTokens));
  EXPECT_FALSE(a.isExpression(falseLongTokens));
}