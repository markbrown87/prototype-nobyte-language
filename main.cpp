#include "lexer.hpp"
#include "parser.hpp"

#include <fstream>

#include <iostream>
#include <stdexcept>

auto main() -> int {
  PSR_NS::Parser p;
  std::string filename = "examples/step1.shl";
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