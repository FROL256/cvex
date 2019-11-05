#include <iostream>
#include "../include/vfloat4_gcc.h"

#include <cmath>

using namespace cvex;

bool vf4_test001_basic_arithmetic()
{
  const vfloat4 Cx1 = {1.0f, 2.0f, 3.0f, 4.0f};
  const vfloat4 Cx2 = {5.0f, 5.0f, 6.0f, 7.0f};

  const auto Cx3 = Cx1 - Cx2;
  const auto Cx4 = (Cx1 + Cx2)*Cx1;
  const auto Cx5 = (Cx2 - Cx1)/Cx1;

  float result1[4];
  float result2[4];
  float result3[4];

  cvex::store_u(result1, Cx3);
  cvex::store_u(result2, Cx4);
  cvex::store_u(result3, Cx5);
  
  // check 
  //
  bool passed = true;

  for(int i=0;i<4;i++)
  {
    const float expr1 = Cx1[i] - Cx2[i];
    const float expr2 = (Cx1[i] + Cx2[i])*Cx1[i];
    const float expr3 = (Cx2[i] - Cx1[i])/Cx1[i];

    if(fabs(result1[i] - expr1) > 1e-6f || fabs(result2[i] - expr2) > 1e-6f || fabs(result3[i] - expr3) > 1e-6f)  
    {
      passed = false;
      break;
    } 
  }
  
  return passed;
}

bool vi4_test002_basic_arithmetic()
{
  const vint4 Cx1 = {10, 20, -3, 4};
  const vint4 Cx2 = {50, -5, 6,  7};

  const auto Cx3 = Cx1 - Cx2;
  const auto Cx4 = (Cx1 + Cx2)*Cx1;
  const auto Cx5 = (Cx2 - Cx1)/Cx1;

  int result1[4];
  int result2[4];
  int result3[4];

  cvex::store_u(result1, Cx3);
  cvex::store_u(result2, Cx4);
  cvex::store_u(result3, Cx5);
  
  // check 
  //
  bool passed = true;

  for(int i=0;i<4;i++)
  {
    const int expr1 = Cx1[i] - Cx2[i];
    const int expr2 = (Cx1[i] + Cx2[i])*Cx1[i];
    const int expr3 = (Cx2[i] - Cx1[i])/Cx1[i];

    if(result1[i] - expr1 != 0 || result2[i] - expr2 != 0 || result3[i] - expr3 != 0)  
    {
      passed = false;
      break;
    } 
  }
  
  return passed;
}

bool vu4_test003_basic_arithmetic()
{
  const vuint4 Cx1 = {10, 20, 3, 4};
  const vuint4 Cx2 = {50, +5, 6, 7};

  const auto Cx3 = Cx1 - Cx2;
  const auto Cx4 = (Cx1 + Cx2)*Cx1;
  const auto Cx5 = (Cx2 - Cx1)/Cx1;

  unsigned int result1[4];
  unsigned int result2[4];
  unsigned int result3[4];

  cvex::store_u(result1, Cx3);
  cvex::store_u(result2, Cx4);
  cvex::store_u(result3, Cx5);
  
  // check 
  //
  bool passed = true;

  for(int i=0;i<4;i++)
  {
    const unsigned int expr1 = Cx1[i] - Cx2[i];
    const unsigned int expr2 = (Cx1[i] + Cx2[i])*Cx1[i];
    const unsigned int expr3 = (Cx2[i] - Cx1[i])/Cx1[i];

    if(result1[i] - expr1 != 0 || result2[i] - expr2 != 0 || result3[i] - expr3 != 0)  
    {
      passed = false;
      break;
    } 
  }
  
  return passed;
}