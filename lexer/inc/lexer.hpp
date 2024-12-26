#ifndef LEXER_HPP
#define LEXER_HPP

#include "token_struct.hpp"

#include <fstream>
#include <memory>

// Namespace for Lexer
namespace LXR_NS {
/*
Lexer class that parses and creates an array of tokens
*/
class Lexer {
public:
  Lexer() = delete;
  ~Lexer() {
    p_file.reset();
  }
  Lexer(std::ifstream filehandle);
  Lexer(const Lexer&) = delete;
  Lexer& operator=(const Lexer&) = delete;
  Lexer(Lexer&& other) : p_file(std::move(other.p_file)) {}
  Lexer& operator=(Lexer&& other) {
    p_file = std::move(other.p_file);
    return *this;
  }

  // Gets the next token in the file
  auto getNextToken() noexcept -> const Token&;

  // Get the current token
  auto getCurrentToken() noexcept -> const Token&;

  private:
  Token m_currentToken;
  std::unique_ptr<std::ifstream> p_file;
};
} // namespace LXR_NS

#endif