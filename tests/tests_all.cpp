#include "tests.h"
#include <iostream>
#include <iomanip>      // std::setfill, std::setw

using TestFuncType = bool (*)();

struct TestRun
{
  TestFuncType pTest;
  const char*  pTestName;
};

void run_all_tests()
{
  TestRun tests[] = { 
      { &vf4_test001_basic_arithmetic, "vf4_test001_basic_arithmetic" },
      { &vi4_test002_basic_arithmetic, "vi4_test002_basic_arithmetic" },
      { &vu4_test003_basic_arithmetic, "vu4_test003_basic_arithmetic" },

      { &vf4_test004_basic_arithmetic, "vf4_test004_basic_arithmetic" },
      { &vi4_test005_basic_arithmetic, "vi4_test005_basic_arithmetic" },
      { &vu4_test006_basic_arithmetic, "vu4_test006_basic_arithmetic" },
  };

  const auto arraySize = sizeof(tests)/sizeof(TestRun);

  for(int i=0;i<int(arraySize);i++)
  {
    const bool res = tests[i].pTest();
    std::cout << "test\t" << std::setfill('0') << std::setw(3) << i+1 << "\t";
    if(res)
      std::cout << "PASSED!";
    else 
      std::cout << "FAILED!";
    std::cout << std::endl;
  }

}
