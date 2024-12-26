#include "lexer.hpp"
#include "token_type.hpp"

#include <cctype>
#include <memory>

using namespace LXR_NS;

Lexer::Lexer(std::ifstream filehandle) : p_file(std::make_unique<std::ifstream>(std::move(filehandle))){}

auto Lexer::getNextToken() noexcept -> const Token&{
  char tmp = EOF;

  p_file->get(tmp);

  if (p_file->eof()){
    m_currentToken.strValue = "EOF";
    m_currentToken.type = TokenType::EoF;
  }

  while(std::isspace(tmp) || tmp == '\n')
    p_file->get(tmp);

  if(tmp == '=' || tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/'){
    m_currentToken.strValue = tmp;
    m_currentToken.type = TokenType::OPERATOR;
  }

  if(std::isalpha(tmp)){
    std::string identifier{tmp};
    p_file->get(tmp);
    while(std::isalnum(tmp) && !p_file->eof()){
      identifier += tmp;
      p_file->get(tmp);
    }

    m_currentToken.strValue = identifier;
    m_currentToken.type = TokenType::IDENTIFIER;

    if(identifier == "def" || identifier == "print")
      m_currentToken.type = TokenType::KEYWORD;
  }

  if(std::isdigit(tmp) || tmp == '.'){
    std::string identifier;
    do{
      identifier += tmp;
      p_file->get(tmp);
    } while(std::isdigit(tmp) || tmp == '.');

    m_currentToken.strValue = identifier;
    m_currentToken.type = TokenType::LITERAL;
  }

  return m_currentToken;
}

auto Lexer::getCurrentToken() noexcept -> const Token&{
  return m_currentToken;
}