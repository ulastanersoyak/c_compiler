#include "lexer/lexer.hpp"
#include <cstdlib>
#include <print>

int
main (int argc, char **argv)
{
  if (argc == 1)
    {
      std::println ("usage := ./c_compiler <file_name>.c");
      return EXIT_FAILURE;
    }
  lexer lex{ argv[1] };

  return 0;
}
