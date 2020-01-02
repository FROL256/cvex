#include <iostream>
#include "include/LiteMath.h"

#include "include/vfloat4_gcc.h"
#include "include/vfloat8_gcc.h"
#include "include/vfloat16_gcc.h"

#include "tests/tests.h"

int main(int argc, const char** argv)
{
  run_all_tests();

  cvex16::vfloat16 Cx1{1.0f, 2.0f,  3.0f,  4.0f,  5.0f,  6.0f,  7.0f, 8.0f, 
                       9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f};

  cvex16::vfloat16 Cx2{0.0f, 20.0f, 0.0f, 0.0f, 50.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};

  cvex16::vfloat16 Cx3 = Cx1*2.0f + Cx2;

  CVEX_ALIGNED(64) float testData[16];
  cvex16::store(testData, Cx3);

  for(int i=0;i<16;i++)
    std::cout << Cx3[i] << " ";
  std::cout << std::endl;

#ifdef WIN32
  int test;
  std::cin >> test;
#endif
  return 0;
}
