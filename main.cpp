#include <iostream>

#ifdef WIN32
  #include "include/vfloat4_x64.h"
#else
  #include "include/vfloat4_gcc.h"
#endif 

#include "tests/tests.h"

int main(int argc, const char** argv)
{
  const cvex::vfloat4 Cx1 = {1.0f, 2.0f, 3.0f, 4.0f};
  const cvex::vfloat4 Cx2 = {5.0f, 5.0f, 6.0f, 7.0f};

  const cvex::vfloat4 Cx3 = Cx1 + Cx2;
  const cvex::vfloat4 Cx4 = (Cx1+Cx2)*Cx1;

  float result[4];

  cvex::store_u(result, Cx3);
  for(int i=0;i<4;i++)
    std::cout << result[i] << ", ";
  std::cout << std::endl;

  cvex::store_u(result, Cx4);
  for(int i=0;i<4;i++)
    std::cout << result[i] << ", ";
  std::cout << std::endl;
  
  std::cout << "dot3({1.0f, 2.0f, 3.0f, 4.0f}, {5.0f, 5.0f, 6.0f, 7.0f}) = " << std::endl;
  const cvex::vfloat4 dot3Res = cvex::dot3v(Cx1,Cx2);
  cvex::store_u(result, dot3Res);
  for(int i=0;i<4;i++)
    std::cout << result[i] << ", ";
  std::cout << std::endl;


  std::cout << vf4_test001_basic_arithmetic() << std::endl;
  std::cout << vi4_test002_basic_arithmetic() << std::endl;
  std::cout << vu4_test003_basic_arithmetic() << std::endl;

  std::cout << vf4_test004_basic_arithmetic() << std::endl; //
  std::cout << vi4_test005_basic_arithmetic() << std::endl;
  std::cout << vu4_test006_basic_arithmetic() << std::endl;

  int test;
  std::cin >> test;
  return 0;
}
