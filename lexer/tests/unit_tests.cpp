#include "lexer.hpp"
#include "token_struct.hpp"

#include <gtest/gtest.h>

using namespace LXR_NS;

TEST(Lexer_Class, getNextToken) {
  std::ifstream file("../testdata/step1.nob");
  if (!file.is_open())
    throw std::runtime_error("File: 'step1.nob' failed to open.");
  Lexer lex(std::move(file));

  auto token = lex.getNextToken();
  EXPECT_EQ("x", token.strValue);
  EXPECT_EQ(TokenType::IDENTIFIER, token.type);

  token = lex.getNextToken();
  EXPECT_EQ("=", token.strValue);
  EXPECT_EQ(TokenType::OPERATOR, token.type);

  token = lex.getNextToken();
  EXPECT_EQ("1", token.strValue);
  EXPECT_EQ(TokenType::LITERAL, token.type);
  
  token = lex.getNextToken();
  EXPECT_EQ("print", token.strValue);
  EXPECT_EQ(TokenType::KEYWORD, token.type);
}

TEST(Lexer_Class, getCurrentToken) {
  std::ifstream file("../testdata/step1.nob");
  if (!file.is_open())
    throw std::runtime_error("File: '../testdata/step1.nob' failed to open.");
  Lexer lex(std::move(file));

  auto token = lex.getNextToken();
  EXPECT_EQ("x", token.strValue);
  EXPECT_EQ(TokenType::IDENTIFIER, token.type);

  auto currentToken = lex.getCurrentToken();
  EXPECT_EQ(token.strValue, currentToken.strValue);
  EXPECT_EQ(token.type, currentToken.type);
}