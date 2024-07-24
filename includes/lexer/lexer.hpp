#ifndef LEXER_HPP
#define LEXER_HPP

#include <fstream>
#include <string_view>

#include <token/token.hpp>
#include <utility/source_location.hpp>

class lexer
{
  source_location location{};
  std::ifstream file;

public:
  explicit lexer (std::string_view input_path) : file{ input_path.data () } {}
  [[nodiscard]] constexpr token get_next_token ();
};

#endif // !LEXER_HPP
