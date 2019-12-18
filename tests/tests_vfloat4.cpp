#ifdef WIN32
  #include "include/vfloat4_x64.h"
#else
  #include "include/vfloat4_gcc.h"
#endif 

#include <iostream>
#include <cmath>

using namespace cvex;

bool vf4_test001_basic()
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

bool vi4_test002_basic()
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

bool vu4_test003_basic()
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool vf4_test004_basic()
{
  const vfloat4 Cx1 = {1.0f, 2.0f, 3.0f, 4.0f};
  const float   Cx2 = 5.0f;

  const auto Cx3 = Cx2*(Cx2 - Cx1) - 2.0f;
  const auto Cx4 = 1.0f + (Cx1 + Cx2)*Cx2;
  const auto Cx5 = 3.0f - Cx2/(Cx2 - Cx1);
  const auto Cx6 = (Cx2 + Cx1)/Cx2 + 5.0f;

  CVEX_ALIGNED(16) float result1[4];
  CVEX_ALIGNED(16) float result2[4];
  CVEX_ALIGNED(16) float result3[4];
  CVEX_ALIGNED(16) float result4[4];

  cvex::store(result1, Cx3);
  cvex::store(result2, Cx4);
  cvex::store(result3, Cx5);
  cvex::store(result4, Cx6);
  
  // check 
  //
  bool passed = true;

  for(int i=0;i<4;i++)
  {
    const float expr1 = Cx2*(Cx2 - Cx1[i]) - 2.0f;
    const float expr2 = 1.0f + (Cx1[i] + Cx2)*Cx2;
    const float expr3 = 3.0f - Cx2/(Cx2 - Cx1[i]);
    const float expr4 = (Cx2 + Cx1[i])/Cx2 + 5.0f;

    if(fabs(result1[i] - expr1) > 1e-6f || fabs(result2[i] - expr2) > 1e-6f || 
       fabs(result3[i] - expr3) > 1e-6f || fabs(result4[i] - expr4) > 1e-6f)  
    {
      passed = false;
      break;
    } 
  }
  
  return passed;
}

bool vi4_test005_basic()
{
  const vint4 Cx1 = {1, -2, 3, -4};
  const int   Cx2 = 5;

  const auto Cx3 = Cx2*(Cx2 - Cx1) - 2;
  const auto Cx4 = 1 + (Cx1 + Cx2)*Cx2;
  const auto Cx5 = 3 - Cx2/(Cx2 - Cx1);
  const auto Cx6 = (Cx2 + Cx1)/Cx2 + 5;

  CVEX_ALIGNED(16) int result1[4];
  CVEX_ALIGNED(16) int result2[4];
  CVEX_ALIGNED(16) int result3[4];
  CVEX_ALIGNED(16) int result4[4];

  cvex::store(result1, Cx3);
  cvex::store(result2, Cx4);
  cvex::store(result3, Cx5);
  cvex::store(result4, Cx6);
  
  // check 
  //
  bool passed = true;

  for(int i=0;i<4;i++)
  {
    const int expr1 = Cx2*(Cx2 - Cx1[i]) - 2;
    const int expr2 = 1 + (Cx1[i] + Cx2)*Cx2;
    const int expr3 = 3 - Cx2/(Cx2 - Cx1[i]);
    const int expr4 = (Cx2 + Cx1[i])/Cx2 + 5;

    if(result1[i] != expr1 || result2[i] != expr2 || 
       result3[i] != expr3 || result4[i] != expr4)  
    {
      passed = false;
      break;
    } 
  }
  
  return passed;
}

bool vu4_test006_basic()
{
  const vuint4       Cx1 = {1, 2, 3, 4};
  const unsigned int Cx2 = 5;

  const auto Cx3 = Cx2*(Cx2 - Cx1) - 2;
  const auto Cx4 = 1 + (Cx1 + Cx2)*Cx2;
  const auto Cx5 = 3 - Cx2/(Cx2 - Cx1);
  const auto Cx6 = (Cx2 + Cx1)/Cx2 + 5;

  CVEX_ALIGNED(16) unsigned int result1[4];
  CVEX_ALIGNED(16) unsigned int result2[4];
  CVEX_ALIGNED(16) unsigned int result3[4];
  CVEX_ALIGNED(16) unsigned int result4[4];

  cvex::store(result1, Cx3);
  cvex::store(result2, Cx4);
  cvex::store(result3, Cx5);
  cvex::store(result4, Cx6);
  
  // check 
  //
  bool passed = true;

  for(int i=0;i<4;i++)
  {
    const unsigned int expr1 = Cx2*(Cx2 - Cx1[i]) - 2;
    const unsigned int expr2 = 1 + (Cx1[i] + Cx2)*Cx2;
    const unsigned int expr3 = 3 - Cx2/(Cx2 - Cx1[i]);
    const unsigned int expr4 = (Cx2 + Cx1[i])/Cx2 + 5;

    if(result1[i] != expr1 || result2[i] != expr2 || 
       result3[i] != expr3 || result4[i] != expr4)    
    {
      passed = false;
      break;
    } 
  }
  
  return passed;
}

bool vi4_test007_and_or()
{
  const vint4 Cx1 = {-1, -2, 3, 4};
  const vint4 Cx2 = {+1, +2, 63355, 63355};
  const vint4 Cx3 = {-1, -1, int(0xF0F00000), 0x00000000};

  const auto Cr1 = (Cx1 & (~Cx3)) | Cx2;
  const auto Cr2 = (Cx2 & Cx3)    | Cx1;

  int result1[4];
  int result2[4];

  cvex::store_u(result1, Cr1);
  cvex::store_u(result2, Cr2);

  bool passed = true;

  for(int i=0;i<4;i++)
  {
    const int expr1 = (Cx1[i] & (~Cx3[i])) | Cx2[i];
    const int expr2 = (Cx2[i] & Cx3[i])    | Cx1[i];

    if(result1[i] != expr1 || result2[i] != expr2)    
    {
      passed = false;
      break;
    } 
  }

  return passed;
}

bool vu4_test008_and_or()
{
  const vuint4 Cx1 = {0xFFFFFFFF, (unsigned int)(-2), 3, 4};
  const vuint4 Cx2 = {+1, +2, 63355, 63355};
  const vuint4 Cx3 = {0xFFFFFFFF, 0xFFFFFFFF, 0xF0F00000, 0x00000000};

  const auto Cr1 = (Cx1 & (~Cx3)) | Cx2;
  const auto Cr2 = (Cx2 & Cx3)    | Cx1;

  unsigned int result1[4];
  unsigned int result2[4];

  cvex::store_u(result1, Cr1);
  cvex::store_u(result2, Cr2);

  bool passed = true;

  for(int i=0;i<4;i++)
  {
    const unsigned int expr1 = (Cx1[i] & (~Cx3[i])) | Cx2[i];
    const unsigned int expr2 = (Cx2[i] & Cx3[i])    | Cx1[i];

    if(result1[i] != expr1 || result2[i] != expr2)    
    {
      passed = false;
      break;
    } 
  }

  return passed;
}

bool vi4_test009_shift()
{
  const vint4 Cx1 = {-1, -2, 3, 4};
  const vint4 Cx2 = {+1, +2, 63355, 63355};
  const vint4 Cx3 = {-1, -1, int(0xF0F00000), 0x00000000};

  const auto Cr1 = (Cx1 << 8); // | (Cx2 >> 17);
  const auto Cr2 = (Cx3 >> 9); // | (Cx3 >> 4);

  int result1[4];
  int result2[4];

  cvex::store_u(result1, Cr1);
  cvex::store_u(result2, Cr2);

  bool passed = true;

  for(int i=0;i<4;i++)
  {
    const int expr1 = (Cx1[i] << 8); // | (Cx2[i] >> 17);
    const int expr2 = (Cx3[i] >> 9); //   (Cx3[i] >> 4);

    if(result1[i] != expr1 || result2[i] != expr2)    
    {
      passed = false;
      break;
    } 
  }

  return passed;
}


bool vu4_test010_shift()
{
  const vuint4 Cx1 = {0xFFFFFFFF, (unsigned int)(-2), 3, 4};
  const vuint4 Cx2 = {+1, +2, 63355, 63355};
  const vuint4 Cx3 = {0xFFFFFFFF, 0xFFFFFFFF, 0xF0F00000, 0x00000000};

  const auto Cr1 = (Cx1 << 8) | (Cx2 >> 17); 
  const auto Cr2 = (Cx3 << 9) | (Cx3 >> 4); 

  unsigned int result1[4];
  unsigned int result2[4];

  cvex::store_u(result1, Cr1);
  cvex::store_u(result2, Cr2);

  bool passed = true;

  for(int i=0;i<4;i++)
  {
    const unsigned int expr1 = (Cx1[i] << 8) | (Cx2[i] >> 17);
    const unsigned int expr2 = (Cx3[i] << 9) | (Cx3[i] >> 4); 

    if(result1[i] != expr1 || result2[i] != expr2)    
    {
      passed = false;
      break;
    } 
  }

  return passed;
}


bool vf4_test011_splat()
{
  const vfloat4 Cx1 = cvex::splat(1.0f);
  const vfloat4 Cx2 = cvex::splat(-5.0f);

  float result1[4];
  float result2[4];

  cvex::store_u(result1, Cx1);
  cvex::store_u(result2, Cx2);
  
  // check 
  //
  bool passed = true;

  for(int i=0;i<4;i++)
  {
    if(fabs(result1[i] - 1.0f) > 1e-6f || fabs(result2[i] - (-5.0f)) > 1e-6f)  
    {
      passed = false;
      break;
    } 
  }
  
  return passed;
}


bool vi4_test012_splat()
{
  const vint4 Cx1 = cvex::splat(1);
  const vint4 Cx2 = cvex::splat(-5);

  int result1[4];
  int result2[4];

  cvex::store_u(result1, Cx1);
  cvex::store_u(result2, Cx2);
  
  // check 
  //
  bool passed = true;

  for(int i=0;i<4;i++)
  {
    if(result1[i] != 1 || result2[i] != -5)  
    {
      passed = false;
      break;
    } 
  }
  
  return passed;
}

bool vu4_test013_splat()
{
  const vuint4 Cx1 = cvex::splat((unsigned int)(1));
  const vuint4 Cx2 = cvex::splat(0xFFFF0000);

  unsigned int result1[4];
  unsigned int result2[4];

  cvex::store_u(result1, Cx1);
  cvex::store_u(result2, Cx2);
  
  // check 
  //
  bool passed = true;

  for(int i=0;i<4;i++)
  {
    if(result1[i] != (unsigned int)(1) || result2[i] != 0xFFFF0000)  
    {
      passed = false;
      break;
    } 
  }
  
  return passed;
}