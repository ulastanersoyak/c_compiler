#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include <unordered_map>

#include "utility/source_location.hpp"

enum class token_type
{
  identifier,
  constant,

  keyword,
  open_brace,
  close_brace,
  open_parenthesis,
  close_parenthesis,
  semicolon,
};

const std::unordered_map<std::string, token_type> token_type_lookup{
  { "int", token_type::keyword },
  { "void", token_type::keyword },

  { "{", token_type::open_brace },
  { "}", token_type::close_brace },
  { "(", token_type::open_parenthesis },
  { ")", token_type::close_parenthesis },
  { ";", token_type::semicolon },
};

struct token
{
  source_location loc{};
  token_type type{};
  std::string lexeme;
};

#endif // !TOKEN_HPP
