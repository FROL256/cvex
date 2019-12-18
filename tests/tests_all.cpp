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
      { &vf4_test001_basic, "vf4_test001_basic" },
      { &vi4_test002_basic, "vi4_test002_basic" },
      { &vu4_test003_basic, "vu4_test003_basic" },

      { &vf4_test004_basic, "vf4_test004_basic" },
      { &vi4_test005_basic, "vi4_test005_basic" },
      { &vu4_test006_basic, "vu4_test006_basic" },

      { &vi4_test007_and_or, "vi4_test007_and_or" },
      { &vu4_test008_and_or, "vu4_test008_and_or" },
      { &vi4_test009_shift,  "vi4_test009_shift"  },
      { &vu4_test010_shift,  "vu4_test010_shift"  },

      { &vf4_test011_splat, "vf4_test011_splat" },
      { &vi4_test012_splat, "vi4_test012_splat" },
      { &vu4_test013_splat, "vu4_test013_splat" },
  };

  const auto arraySize = sizeof(tests)/sizeof(TestRun);

  for(int i=0;i<int(arraySize);i++)
  {
    const bool res = tests[i].pTest();
    std::cout << "test\t" << std::setfill('0') << std::setw(3) << i+1 << "\t" << tests[i].pTestName << "\t";
    if(res)
      std::cout << "PASSED!";
    else 
      std::cout << "FAILED!\tFAILED!";
    std::cout << std::endl;
  }

}
