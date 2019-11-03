#include <iostream>
#include "include/vfloat4_gcc.h"

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

  float f = 1.0f;
  for(int i=0;i<50;i++)
  {
    f *= 10.0f;
    std::cout << "f = " << f << std::endl;
  }

  return 0;
}
