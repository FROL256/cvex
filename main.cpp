#include <iostream>
#include "include/LiteMath.h"


#include "tests/tests.h"

int main(int argc, const char** argv)
{
  run_all_tests();

#ifdef WIN32
  int test;
  std::cin >> test;
#endif
  return 0;
}
