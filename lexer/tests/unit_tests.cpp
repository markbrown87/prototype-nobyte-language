#include "lexer.hpp"

#include <gtest/gtest.h>

#include <string>
#include <vector>

using namespace LXR_NS;

TEST(Lexer_Class, lex) {
  std::string line = "7 + 6 + 8\n";
  std::stringstream stream(line);
  std::vector<Token> checkResult = {{"7", TokenType::LITERAL},
                                    {"+", TokenType::OPERATOR},
                                    {"6", TokenType::LITERAL},
                                    {"+", TokenType::OPERATOR},
                                    {"8", TokenType::LITERAL}};

  Lexer lexer;
  auto retResult = lexer.lex(stream);

  EXPECT_EQ(retResult.size(), 5);

  for (auto i = 0; i < retResult.size(); ++i) {
    EXPECT_EQ(retResult[i].strValue, checkResult[i].strValue);
    EXPECT_EQ(retResult[i].type, checkResult[i].type);
  }
}

TEST(Lexer_Class, lex_no_endline_char) {
  std::string line = "7 - 6";
  std::stringstream stream(line);
  std::vector<Token> checkResult = {{"7", TokenType::LITERAL},
                                    {"-", TokenType::OPERATOR},
                                    {"6", TokenType::LITERAL}};

  Lexer lexer;
  auto retResult = lexer.lex(stream);

  EXPECT_EQ(retResult.size(), 3);

  for (auto i = 0; i < retResult.size(); ++i) {
    EXPECT_EQ(retResult[i].strValue, checkResult[i].strValue);
    EXPECT_EQ(retResult[i].type, checkResult[i].type);
  }
}