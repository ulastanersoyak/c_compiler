#ifndef SOURCE_LOCATION_HPP
#define SOURCE_LOCATION_HPP

#include <cstddef>

struct source_location
{
  std::size_t column{ 0 };
  std::size_t row{ 0 };

  source_location &
  operator++ ()
  {
    ++this->row;
    return *this;
  }

  source_location
  operator++ (int)
  {
    source_location temp{ *this };
    this->operator++ ();
    return temp;
  }
};

#endif // !SOURCE_LOCATION_HPP
