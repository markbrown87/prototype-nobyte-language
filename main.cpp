#include "lexer.hpp"
#include "parser.hpp"

#include <fstream>

#include <iostream>
#include <stdexcept>

auto main(int argc, char *argv[]) -> int {
  // TODO
  // - Move this to argument parser
  std::string filename = "examples/step1.shl";
  if (argc > 1 && std::string(argv[1]) == "-f") 
    filename = argv[2];
  std::cout << "Compiling File: " << filename << std::endl;


  PSR_NS::Parser p{};
  std::fstream file(filename);

  if (!file.is_open())
    throw std::runtime_error("File: '" + filename + "' failed to open.");

  LXR_NS::Lexer A;
  std::stringstream stream;
  stream << file.rdbuf();

  auto tokens = A.lex(stream);
  std::cout << "Token vector size: " << tokens.size() << std::endl;
  for (auto &[value, type] : tokens) {
    std::cout << "Lexer found value: " << value << " of type: " << type
              << std::endl;
  }

  if (!p.analysis(tokens))
    throw std::runtime_error("File: '" + filename +
                             "' does not grammacially work.");
}