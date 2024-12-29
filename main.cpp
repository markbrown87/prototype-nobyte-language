#include "lexer.hpp"
#include "parser.hpp"

#include <fstream>

#include <iostream>
#include <memory>
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

  auto lexer = std::make_unique<LXR_NS::Lexer>(std::move(file));
  PSR_NS::Parser parser(std::move(lexer));

  return parser.process();
}