#include "borrow.hpp"

int
main() {
  using ::borrow::borrow;

  int value = 1;
  BEGIN_LIFETIME($1);
  BEGIN_LIFETIME($2);

  auto p1 = borrow<$1>(value);
  auto p2 = borrow<$2>(p1);
  *p2;
  static_assert(::std::is_same<decltype(*p2), int const&>::value);

  END_LIFETIME($1);
  *p2; // compiler error here
  END_LIFETIME($2);
}
