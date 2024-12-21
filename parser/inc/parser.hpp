#ifndef PARSER_HPP
#define PARSER_HPP

// Namespace for Parser
namespace PSR_NS {
/*
Parser class that analyzes the stream of tokens to determine the grammatical structure of the code and creates the AST.
*/
class Parser {
public:
  Parser() = default;

  /*
  DOES STUFF
  */
  auto analysis() -> void;
};
} // namespace PSR_NS

#endif