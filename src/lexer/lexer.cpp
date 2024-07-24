#include "lexer/lexer.hpp"
#include "token/token.hpp"

static constexpr bool
is_single_digit_lexeme (char c)
{
  return c == '{' || c == '}' || c == '(' || c == ')' || c == ';';
}

[[nodiscard]] constexpr token
lexer::get_next_token ()
{
  char c{ 0 };
  std::string lexeme;
  while (this->file >> c)
    {
      if (lexeme.empty ())
        {
          if (c == ' ')
            {
              ++this->location.column;
              continue;
            }
          if (c == '\n')
            {
              this->location.column = 0;
              ++this->location.row;
              continue;
            }
          if (is_single_digit_lexeme (c))
            {
              return { .loc = this->location++,
                       .type = token_type_lookup.at (std::string{ c }),
                       .lexeme = std::string{ c } };
            }
          lexeme.append (std::string{ c });
          this->location.row++;
        }
      else
        {
          if (is_single_digit_lexeme (c) || c != ' ' || c != '\n')
            {
              lexeme.append (std::string{ c });
              this->location.row++;
            }
          else
            {
              if (token_type_lookup.contains (lexeme))
                {
                  return { .loc = this->location++,
                           .type = token_type_lookup.at (lexeme),
                           .lexeme = std::string{ lexeme } };
                }
            }
        }
    }
  return {};
}
