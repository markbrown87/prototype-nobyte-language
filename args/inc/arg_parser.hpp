#ifndef ARG_PARSER_HPP
#define ARG_PARSER_HPP

#include "arg_config.hpp"

// Namespace for Argument Parser
namespace ARG_NS {
/*
Parser class for parsing arguments passed into the application.
*/
class ArgParser {
public:
  ArgParser() = default;

  auto parse(int argc, char *argv[]) const -> ConfigList;
};
} // namespace ARG_NS

#endif