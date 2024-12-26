#include "lexer.hpp"
#include "token_type.hpp"
// #include "parser.hpp"

#include <fstream>

#include <iostream>
#include <stdexcept>

auto main(int argc, char *argv[]) -> int {
  // TODO
  // - Move this to argument parser
  std::string filename = "examples/step1.nob";
  if (argc > 1 && std::string(argv[1]) == "-f")
    filename = argv[2];
  std::cout << "Compiling File: " << filename << std::endl;

  // PSR_NS::Parser p{};
  std::ifstream file(filename);
  if (!file.is_open())
    throw std::runtime_error("File: '" + filename + "' failed to open.");

  LXR_NS::Lexer lexer(std::move(file));
  std::cout << "Progam Processing Starting..." << std::endl;
  while(true){
    switch(lexer.getNextToken().type){
      case LXR_NS::TokenType::IDENTIFIER:
        std::cout << "Processing Identifier: " << lexer.getCurrentToken().strValue << std::endl;
        break;
      case LXR_NS::TokenType::KEYWORD:
        std::cout << "Processing Keyword: " << lexer.getCurrentToken().strValue << std::endl;
        break;
      case LXR_NS::TokenType::SEPARATOR:
        std::cout << "Processing Separator: " << lexer.getCurrentToken().strValue << std::endl;
        break;
      case LXR_NS::TokenType::OPERATOR:
        std::cout << "Processing Operator: " << lexer.getCurrentToken().strValue << std::endl;
        break;
      case LXR_NS::TokenType::LITERAL:
        std::cout << "Processing Literal: " << lexer.getCurrentToken().strValue << std::endl;
        break;
      case LXR_NS::TokenType::COMMENT:
        std::cout << "Processing Comment: " << lexer.getCurrentToken().strValue << std::endl;
        break;
      case LXR_NS::TokenType::EoF:
        std::cout << "End of File and processing." << std::endl;
        return 0;
      default:
        std::cout << "Error: Should have a case in type." << std::endl;
        return 1;
    }
  }
}