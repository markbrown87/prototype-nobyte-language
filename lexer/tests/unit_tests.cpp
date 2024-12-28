#include "lexer.hpp"
#include "token_struct.hpp"

#include <gtest/gtest.h>

using namespace LXR_NS;

TEST(Lexer_Class, getNextToken) {
  std::ifstream file("lexer_testdata.nob");
  if (!file.is_open())
    throw std::runtime_error("File: 'lexer_testdata.nob' failed to open.");
  Lexer lex(std::move(file));

  auto token = lex.getNextToken();
  EXPECT_EQ("x", token.strValue);
  EXPECT_EQ(TokenType::IDENTIFIER, token.type);

  token = lex.getNextToken();
  EXPECT_EQ("=", token.strValue);
  EXPECT_EQ(TokenType::OPERATOR, token.type);

  token = lex.getNextToken();
  EXPECT_EQ("2", token.strValue);
  EXPECT_EQ(TokenType::LITERAL, token.type);

  token = lex.getNextToken();
  EXPECT_EQ("+", token.strValue);
  EXPECT_EQ(TokenType::OPERATOR, token.type);

  token = lex.getNextToken();
  EXPECT_EQ("5", token.strValue);
  EXPECT_EQ(TokenType::LITERAL, token.type);

  token = lex.getNextToken();
  EXPECT_EQ("print", token.strValue);
  EXPECT_EQ(TokenType::KEYWORD, token.type);
}

TEST(Lexer_Class, getCurrentToken) {
  std::ifstream file("lexer_testdata.nob");
  if (!file.is_open())
    throw std::runtime_error("File: 'lexer_testdata.nob' failed to open.");
  Lexer lex(std::move(file));

  auto token = lex.getNextToken();
  EXPECT_EQ("x", token.strValue);
  EXPECT_EQ(TokenType::IDENTIFIER, token.type);

  auto currentToken = lex.getCurrentToken();
  EXPECT_EQ(token.strValue, currentToken.strValue);
  EXPECT_EQ(token.type, currentToken.type);
}