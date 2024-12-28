#ifndef TOKEN_TYPE_HPP
#define TOKEN_TYPE_HPP

// Namespace for Lexer
namespace LXR_NS {
/*
Enum type representing token type
*/
enum TokenType {
  IDENTIFIER, // Names assigned by developer
  KEYWORD,    // Reserved word
  SEPARATOR,  // Punctuation chars and paried delimiters --> i.e. ';' or '{' ,
              // '}'
  OPERATOR,   // Operate on arguments and produce results --> i.e. '+', '-'
  LITERAL,    // Numeric, logical, textual, and reference literals
  COMMENT,    // Line/block comments
  // WHITESPACE, // Non printable chars
  EoF // End of File
};
} // namespace LXR_NS

#endif