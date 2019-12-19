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

bool vfi4_test014_convert()
{
  const vint4  Cx1 = cvex::splat(-2456);
  const vuint4 Cx2 = cvex::splat(0xFFFFFF00);

  const vfloat4 Cf1 = to_float32(Cx1);
  const vfloat4 Cf2 = to_float32(Cx2);

  float result1[4];
  float result2[4];

  cvex::store_u(result1, Cf1);
  cvex::store_u(result2, Cf2);

  // check 
  //
  bool passed = true;
  
  const float res1 = float(-2456);
  const float res2 = float(0xFFFFFF00);

  for (int i = 0; i<4; i++)
  {
    if (fabs(result1[i] - res1) > 1e-6f || fabs(result2[i] - res2) > 1e-6f)
    {
      passed = false;
      break;
    }
  }

  return passed;
}

bool viu4_test015_convert()
{
  const vfloat4 Cx1 = { -334324.0f, -0.0f, 1.0f, 23423523.0f };
  const vfloat4 Cx2 = { -10000.0f, 0.0f, 100.0f, 0.000005f };

  const vint4  Cr1 = to_int32(Cx1);
  const vuint4 Cr2 = to_uint32(Cx2);
  const vuint4 Cr3 = to_uint32(Cr1);
  const vint4  Cr4 = to_int32(Cr2);

  int          result1[4];
  unsigned int result2[4];
  unsigned int result3[4];
  int          result4[4];

  cvex::store_u(result1, Cr1);
  cvex::store_u(result2, Cr2);
  cvex::store_u(result3, Cr3);
  cvex::store_u(result4, Cr4);

  // check 
  //
  bool passed = true;

  const int          res1[4] = { int(-334324.0f), int(-0.0f), int(1.0f), int(23423523.0f) };
  const unsigned int res2[4] = { (unsigned int)(-10000.0f),  (unsigned int)(0.0f),  (unsigned int)(100.0f),  (unsigned int)(0.000005f) };
  const unsigned int res3[4] = { (unsigned int)(res1[0]), (unsigned int)(res1[1]), (unsigned int)(res1[2]), (unsigned int)(res1[3]) };
  const          int res4[4] = { (int)(res2[0]), (int)(res2[1]), (int)(res2[2]), (int)(res2[3]) };

  for (int i=0; i<4; i++)
  {
    if (result1[i] != res1[i] || result2[i] != res2[i] || 
        result3[i] != res3[i] || result4[i] != res4[i])
    {
      passed = false;
      break;
    }
  }

  return passed;
}

bool vfi4_test016_cast()
{
  const vfloat4 Cx1 = { -334324.0f, -0.0f, 1.0f, 23423523.0f };
  const vfloat4 Cx2 = { -10000.0f, 0.0f, 100.0f, 0.000005f };
  
  const vint4   Cx3 = as_int32(Cx1);
  const vuint4  Cx4 = as_uint32(Cx2);

  const vfloat4 Cr1 = as_float32(Cx3);
  const vfloat4 Cr2 = as_float32(Cx4);

  float result1[4];
  float result2[4];
  cvex::store_u(result1, Cr1);
  cvex::store_u(result2, Cr2);

  bool passed = true;

  const float res1[4] = { -334324.0f, -0.0f, 1.0f, 23423523.0f };
  const float res2[4] = { -10000.0f,  0.0f,  100.0f, 0.000005f };
 
  for (int i = 0; i<4; i++)
  {
    if (result1[i] != res1[i] || result2[i] != res2[i])
    {
      passed = false;
      break;
    }
  }

  return passed;
}


bool vf4_test017_mMcRcp()
{
  const vfloat4 Cx1 = { +10000.0f,  -1.0f, 1.0f,   -99999999.0f };
  const vfloat4 Cx2 = { +334324.0f, +1.0f, 100.0f, -0.000005f };
  const vfloat4 Cx3 = { +10.0f,  +10.0f, +10.0f, +10.0f };

  const vfloat4 Cr1 = cvex::min(Cx1, Cx2);
  const vfloat4 Cr2 = cvex::max(Cx1, Cx2);
  const vfloat4 Cr3 = cvex::clamp(Cx3, Cx1, Cx2);
  const vfloat4 Cr4 = cvex::rcp_e(Cx2);

  float result1[4];
  float result2[4];
  float result3[4];
  float result4[4];

  cvex::store_u(result1, Cr1);
  cvex::store_u(result2, Cr2);
  cvex::store_u(result3, Cr3);
  cvex::store_u(result4, Cr4);

  bool passed = true;

  const float res1[4] = { +10000.0f,  -1.0f, 1.0f,   -99999999.0f };
  const float res2[4] = { +334324.0f, +1.0f, 100.0f, -0.000005f };
  const float res3[4] = { +10000.0f,  +1.0f, +10.0f, -0.000005f };
  const float res4[4] = { 1.0f/Cx2[0],  1.0f / Cx2[1], 1.0f / Cx2[2], 1.0f / Cx2[3] };

  for (int i = 0; i<4; i++)
  {
    const bool b1 = fabs(result1[i] - res1[i]) > 1e-6f;
    const bool b2 = fabs(result2[i] - res2[i]) > 1e-6f;
    const bool b3 = fabs(result3[i] - res3[i]) > 1e-6f;
    const bool b4 = fabs(result4[i] - res4[i]) > 1e-3f;

    if (b1 || b2 || b3 || b4)
    {
      passed = false;
      break;
    }
  }
  return passed;
}

bool vi4_test018_minMax()
{
  const vint4 Cx1 = { 10000,  -1, 1, -99999999 };
  const vint4 Cx2 = { 334324, +1, 100, 1 };
  const vint4 Cx3 = { 10,  10, +10, +10 };

  const vint4 Cr1 = cvex::min(Cx1, Cx2);
  const vint4 Cr2 = cvex::max(Cx1, Cx2);
  const vint4 Cr3 = cvex::clamp(Cx3, Cx1, Cx2);

  int result1[4];
  int result2[4];
  int result3[4];

  cvex::store_u(result1, Cr1);
  cvex::store_u(result2, Cr2);
  cvex::store_u(result3, Cr3);

  bool passed = true;

  const int res1[4] = { 10000,  -1, 1, -99999999 };
  const int res2[4] = { 334324, +1, 100, 1 };
  const int res3[4] = { 10000,  +1, 10,  1};

  for (int i = 0; i<4; i++)
  {
    const bool b1 = result1[i] != res1[i];
    const bool b2 = result2[i] != res2[i];
    const bool b3 = result3[i] != res3[i];

    if (b1 || b2 || b3)
    {
      passed = false;
      break;
    }
  }

  return passed;
}

bool vu4_test019_minMax()
{
  const vuint4 Cx1 = { 10000,  1,  1,   1 };
  const vuint4 Cx2 = { 334324, 1,  100, 99999999 };
  const vuint4 Cx3 = { 10,     10, 10,  10 };

  const vuint4 Cr1 = cvex::min(Cx1, Cx2);
  const vuint4 Cr2 = cvex::max(Cx1, Cx2);
  const vuint4 Cr3 = cvex::clamp(Cx3, Cx1, Cx2);

  unsigned int result1[4];
  unsigned int result2[4];
  unsigned int result3[4];

  cvex::store_u(result1, Cr1);
  cvex::store_u(result2, Cr2);
  cvex::store_u(result3, Cr3);

  bool passed = true;

  const unsigned int res1[4] = { 10000,  1, 1,   1 };
  const unsigned int res2[4] = { 334324, 1, 100, 99999999 };
  const unsigned int res3[4] = { 10000,  1, 10,  10 };

  for (int i = 0; i<4; i++)
  {
    const bool b1 = result1[i] != res1[i];
    const bool b2 = result2[i] != res2[i];
    const bool b3 = result3[i] != res3[i];

    if (b1 || b2 || b3)
    {
      passed = false;
      break;
    }
  }

  return passed;
}

bool vf4_test020_blend()
{
  const vfloat4 Cx1  = { +1.0f, +2.0f, +3.0f, +4.0f };
  const vfloat4 Cx2  = { -1.0f, -2.0f, -3.0f, -4.0f };

  const vint4 mask1  = {int(0xFFFFFFFF), 0, int(0xFFFFFFFF), 0};
  const vuint4 mask2 = {0, 0xFFFFFFFF, 0xFFFFFFFF, 0 };

  const vfloat4 Cr1 = cvex::blend(Cx1, Cx2, mask1);
  const vfloat4 Cr2 = cvex::blend(Cx1, Cx2, mask2);

  float result1[4];
  float result2[4];
  cvex::store_u(result1, Cr1);
  cvex::store_u(result2, Cr2);

  bool passed = true;

  const float res1[4] = { +1.0f, -2.0f, +3.0f, -4.0f };
  const float res2[4] = { -1.0f, +2.0f, +3.0f, -4.0f };

  for (int i = 0; i<4; i++)
  {
    const bool b1 = fabs(result1[i] - res1[i]) > 1e-6f;
    const bool b2 = fabs(result2[i] - res2[i]) > 1e-6f;

    if (b1 || b2)
    {
      passed = false;
      break;
    }
  }
  return passed;
}

bool vi4_test021_blend()
{
  const vint4 Cx1 = { +1, +2, +3, +4 };
  const vint4 Cx2 = { -1, -2, -3, -4 };

  const vint4 mask1 = { int(0xFFFFFFFF), 0, int(0xFFFFFFFF), 0 };
  const vint4 mask2 = { 0, int(0xFFFFFFFF), int(0xFFFFFFFF), 0 };

  const vint4 Cr1 = cvex::blend(Cx1, Cx2, mask1);
  const vint4 Cr2 = cvex::blend(Cx1, Cx2, mask2);

  int result1[4];
  int result2[4];
  cvex::store_u(result1, Cr1);
  cvex::store_u(result2, Cr2);

  bool passed = true;

  const int res1[4] = { +1, -2, +3, -4 };
  const int res2[4] = { -1, +2, +3, -4 };

  for (int i = 0; i<4; i++)
  {
    if (result1[i] != res1[i] || result2[i] != res2[i])
    {
      passed = false;
      break;
    }
  }
  return passed;
}


bool vu4_test022_blend()
{
  const vuint4 Cx1 = { +1, +2, +3, +4 };
  const vuint4 Cx2 = { (unsigned int)-1, (unsigned int)-2, (unsigned int)-3, (unsigned int)-4 };

  const vuint4 mask1 = { 0xFFFFFFFF, 0, 0xFFFFFFFF, 0 };
  const vuint4 mask2 = { 0, 0xFFFFFFFF, 0xFFFFFFFF, 0 };

  const vuint4 Cr1 = cvex::blend(Cx1, Cx2, mask1);
  const vuint4 Cr2 = cvex::blend(Cx1, Cx2, mask2);

  unsigned int result1[4];
  unsigned int result2[4];
  cvex::store_u(result1, Cr1);
  cvex::store_u(result2, Cr2);

  bool passed = true;

  const unsigned int res1[4] = { +1,  (unsigned int)-2, +3,  (unsigned int)-4 };
  const unsigned int res2[4] = { (unsigned int)-1, +2, +3,  (unsigned int)-4 };

  for (int i = 0; i<4; i++)
  {
    if (result1[i] != res1[i] || result2[i] != res2[i])
    {
      passed = false;
      break;
    }
  }
  return passed;
}

bool vf4_test023_floor_ceil()
{
  const vfloat4 Cx1 = { +1.5f, -2.5f, +3.2f, -4.8f };

  const vfloat4 Cr1 = cvex::floor(Cx1);
  const vfloat4 Cr2 = cvex::ceil(Cx1);

  CVEX_ALIGNED(16) float result1[4];
  CVEX_ALIGNED(16) float result2[4];
  cvex::store(result1, Cr1);
  cvex::store(result2, Cr2);

  const float res1[4] = { +1.0f, -3.0f, +3.0f, -5.0f };
  const float res2[4] = { +2.0f, -2.0f, +4.0f, -4.0f };

  bool passed = true;
  for (int i = 0; i<4; i++)
  {
    const bool b1 = fabs(result1[i] - res1[i]) > 1e-10f;
    const bool b2 = fabs(result2[i] - res2[i]) > 1e-10f;

    if (b1 || b2)
    {
      passed = false;
      break;
    }
  }
  return passed;
}

bool vfiu_test024_test_bits()
{
  const vfloat4 Cx1 = { 0.0f, 0.5f, 0.0f, 0.0f };
  const vfloat4 Cx2 = { 0.0f, 0.0f, 0.0f, 0.0f };

  const vint4 Cx3 = { 0, 0, 4, 0 };
  const vint4 Cx4 = { 0, 0, 0, 0 };

  const vuint4 Cx5 = { 0, 0, 0, 8 };
  const vuint4 Cx6 = { 0, 0, 0, 0 };

  const bool b1 = cvex::test_bits_any(Cx1);
  const bool b2 = cvex::test_bits_any(Cx2);
  const bool b3 = cvex::test_bits_any(Cx3);
  const bool b4 = cvex::test_bits_any(Cx4);
  const bool b5 = cvex::test_bits_any(Cx5);
  const bool b6 = cvex::test_bits_any(Cx6);

  return (b1 && !b2 && b3 && !b4 && b5 && !b6);
}

bool vfiu_test025_test_bits()
{
  const vfloat4 Cx1 = { 0.0f, 0.5f, 0.0f, 0.0f };
  const vfloat4 Cx2 = { 0.0f, 0.0f, 0.0f, 0.0f };

  const vint4 Cx3 = { -1, -1, -1, -1 };
  const vint4 Cx4 = { -1, -1, -1, -10 };

  const vuint4 Cx5 = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
  const vuint4 Cx6 = { 0xFFFFFFFF, 0, 0xFFFFFFFF, 0xFFFFFFFF };

  const bool b1 = cvex::test_bits_all(Cx1);
  const bool b2 = cvex::test_bits_all(Cx2);
  const bool b3 = cvex::test_bits_all(Cx3);
  const bool b4 = cvex::test_bits_all(Cx4);
  const bool b5 = cvex::test_bits_all(Cx5);
  const bool b6 = cvex::test_bits_all(Cx6);

  return (!b1 && !b2 && b3 && !b4 && b5 && !b6);
}

bool vf4_test026_dot_cross()
{
  const cvex::vfloat4 Cx1 = { 1.0f, 2.0f, 3.0f, 4.0f };
  const cvex::vfloat4 Cx2 = { 5.0f, 6.0f, 7.0f, 8.0f };

  const float   dot1 = cvex::dot3f(Cx1, Cx2);
  const vfloat4 dot2 = cvex::dot3v(Cx1, Cx2);
  const float   dot3 = cvex::dot4f(Cx1, Cx2);
  const vfloat4 dot4 = cvex::dot4v(Cx1, Cx2);
  const vfloat4 crs3 = cvex::cross3(Cx1, Cx2);

  CVEX_ALIGNED(16) float result1[4];
  CVEX_ALIGNED(16) float result2[4];
  CVEX_ALIGNED(16) float result3[4];
  cvex::store(result1, dot2);
  cvex::store(result2, dot4);
  cvex::store(result3, crs3);

  const float ref_dp3 = 1.0f*5.0f + 2.0f*6.0f + 3.0f*7.0f;
  const float ref_dp4 = 1.0f*5.0f + 2.0f*6.0f + 3.0f*7.0f + 4.0f*8.0f;

  const float crs_ref[3] = { Cx1[1]*Cx2[2] - Cx1[2]*Cx2[1], 
                             Cx1[2]*Cx2[0] - Cx1[0]*Cx2[2], 
                             Cx1[0]*Cx2[1] - Cx1[1]*Cx2[0] };

  const bool b1 = fabs(dot1 - ref_dp3) < 1e-6f;
  const bool b2 = fabs(result1[0] - ref_dp3) < 1e-6f && 
                  fabs(result1[1] - ref_dp3) < 1e-6f && 
                  fabs(result1[2] - ref_dp3) < 1e-6f &&
                  fabs(result1[3] - ref_dp3) < 1e-6f;

  const bool b3 = fabs(dot3 - ref_dp4) < 1e-6f;
  const bool b4 = fabs(result2[0] - ref_dp4) < 1e-6f &&
                  fabs(result2[1] - ref_dp4) < 1e-6f &&
                  fabs(result2[2] - ref_dp4) < 1e-6f &&
                  fabs(result2[3] - ref_dp4) < 1e-6f;

  const bool b5 = fabs(result3[0] - crs_ref[0]) < 1e-6f && 
                  fabs(result3[1] - crs_ref[1]) < 1e-6f &&
                  fabs(result3[2] - crs_ref[2]) < 1e-6f;

  return b1 && b2 && b3 && b4 && b5;
}

bool vf4_test027_shuffle()
{
  const cvex::vfloat4 Cx1 = { 1.0f, 2.0f, 3.0f, 4.0f };

  const cvex::vfloat4 Cr1 = shuffle_zyxw(Cx1);
  const cvex::vfloat4 Cr2 = shuffle_yzxw(Cx1);
  const cvex::vfloat4 Cr3 = shuffle_zxyw(Cx1);
  const cvex::vfloat4 Cr4 = shuffle_xyxy(Cx1);
  const cvex::vfloat4 Cr5 = shuffle_zwzw(Cx1);

  CVEX_ALIGNED(16) float result1[4];
  CVEX_ALIGNED(16) float result2[4];
  CVEX_ALIGNED(16) float result3[4];
  CVEX_ALIGNED(16) float result4[4];
  CVEX_ALIGNED(16) float result5[4];
  cvex::store(result1, Cr1);
  cvex::store(result2, Cr2);
  cvex::store(result3, Cr3);
  cvex::store(result4, Cr4);
  cvex::store(result5, Cr5);

  const bool b1 = (result1[0] == 3.0f) && (result1[1] == 2.0f) && (result1[2] == 1.0f) && (result1[3] == 4.0f);
  const bool b2 = (result2[0] == 2.0f) && (result2[1] == 3.0f) && (result2[2] == 1.0f) && (result2[3] == 4.0f);
  const bool b3 = (result3[0] == 3.0f) && (result3[1] == 1.0f) && (result3[2] == 2.0f) && (result3[3] == 4.0f);
  const bool b4 = (result4[0] == 1.0f) && (result4[1] == 2.0f) && (result4[2] == 1.0f) && (result4[3] == 2.0f);
  const bool b5 = (result5[0] == 3.0f) && (result5[1] == 4.0f) && (result5[2] == 3.0f) && (result5[3] == 4.0f);
 
  return (b1 && b2 && b3 && b4 && b5);
}

bool vf4_test028_length()
{
  const cvex::vfloat4 Cx1 = { 1.0f, 2.0f, 3.0f, 4.0f };

  const float   dot1 = cvex::length3f(Cx1);
  const vfloat4 dot2 = cvex::length3v(Cx1);
  const float   dot3 = cvex::length4f(Cx1);
  const vfloat4 dot4 = cvex::length4v(Cx1);

  CVEX_ALIGNED(16) float result1[4];
  CVEX_ALIGNED(16) float result2[4];
  cvex::store(result1, dot2);
  cvex::store(result2, dot4);

  const float ref_dp3 = sqrtf(1.0f*1.0f + 2.0f*2.0f + 3.0f*3.0f);
  const float ref_dp4 = sqrtf(1.0f*1.0f + 2.0f*2.0f + 3.0f*3.0f + 4.0f*4.0f);

  const bool b1 = fabs(dot1 - ref_dp3) < 1e-6f;
  const bool b2 = fabs(result1[0] - ref_dp3) < 1e-6f && 
                  fabs(result1[1] - ref_dp3) < 1e-6f && 
                  fabs(result1[2] - ref_dp3) < 1e-6f &&
                  fabs(result1[3] - ref_dp3) < 1e-6f;

  const bool b3 = fabs(dot3 - ref_dp4) < 1e-6f;
  const bool b4 = fabs(result2[0] - ref_dp4) < 1e-6f &&
                  fabs(result2[1] - ref_dp4) < 1e-6f &&
                  fabs(result2[2] - ref_dp4) < 1e-6f &&
                  fabs(result2[3] - ref_dp4) < 1e-6f;
                  
  return (b1 && b2 && b3 && b4);
}

bool vf4_test029_ext_splt()
{
  const cvex::vfloat4 Cx1 = { 1.0f, 2.0f, 3.0f, 4.0f };

  const cvex::vfloat4 Cr1 = splat_0(Cx1);
  const cvex::vfloat4 Cr2 = splat_1(Cx1);
  const cvex::vfloat4 Cr3 = splat_2(Cx1);
  const cvex::vfloat4 Cr4 = splat_3(Cx1);

  CVEX_ALIGNED(16) float result1[4];
  CVEX_ALIGNED(16) float result2[4];
  CVEX_ALIGNED(16) float result3[4];
  CVEX_ALIGNED(16) float result4[4];

  cvex::store(result1, Cr1);
  cvex::store(result2, Cr2);
  cvex::store(result3, Cr3);
  cvex::store(result4, Cr4);


  const float x = extract_0(Cx1);
  const float y = extract_1(Cx1);
  const float z = extract_2(Cx1);
  const float w = extract_3(Cx1);

  bool passed = true;
  for (int i = 0; i<4; i++)
  {
    const bool b1 = (result1[i] == 1.0f);
    const bool b2 = (result2[i] == 2.0f);
    const bool b3 = (result3[i] == 3.0f);
    const bool b4 = (result4[i] == 4.0f);

    if (!b1 || !b2 || !b3 || !b4)
    {
      passed = false;
      break;
    }
  }
  return passed && (x == 1.0f) && (y == 2.0f) && (z == 3.0f) && (w == 4.0f);
}


bool vi4_test030_ext_splt()
{
  const cvex::vint4 Cx1 = { 1, 2, 3, 4 };

  const cvex::vint4 Cr1 = splat_0(Cx1);
  const cvex::vint4 Cr2 = splat_1(Cx1);
  const cvex::vint4 Cr3 = splat_2(Cx1);
  const cvex::vint4 Cr4 = splat_3(Cx1);

  CVEX_ALIGNED(16) int result1[4];
  CVEX_ALIGNED(16) int result2[4];
  CVEX_ALIGNED(16) int result3[4];
  CVEX_ALIGNED(16) int result4[4];

  cvex::store(result1, Cr1);
  cvex::store(result2, Cr2);
  cvex::store(result3, Cr3);
  cvex::store(result4, Cr4);


  const int x = extract_0(Cx1);
  const int y = extract_1(Cx1);
  const int z = extract_2(Cx1);
  const int w = extract_3(Cx1);

  bool passed = true;
  for (int i = 0; i<4; i++)
  {
    const bool b1 = (result1[i] == 1);
    const bool b2 = (result2[i] == 2);
    const bool b3 = (result3[i] == 3);
    const bool b4 = (result4[i] == 4);

    if (!b1 || !b2 || !b3 || !b4)
    {
      passed = false;
      break;
    }
  }
  return passed && (x == 1) && (y == 2) && (z == 3) && (w == 4);
}

bool vu4_test031_ext_splt()
{
  const cvex::vuint4 Cx1 = { 1, 2, 3, 4 };

  const cvex::vuint4 Cr1 = splat_0(Cx1);
  const cvex::vuint4 Cr2 = splat_1(Cx1);
  const cvex::vuint4 Cr3 = splat_2(Cx1);
  const cvex::vuint4 Cr4 = splat_3(Cx1);

  CVEX_ALIGNED(16) unsigned int result1[4];
  CVEX_ALIGNED(16) unsigned int result2[4];
  CVEX_ALIGNED(16) unsigned int result3[4];
  CVEX_ALIGNED(16) unsigned int result4[4];

  cvex::store(result1, Cr1);
  cvex::store(result2, Cr2);
  cvex::store(result3, Cr3);
  cvex::store(result4, Cr4);


  const unsigned int x = extract_0(Cx1);
  const unsigned int y = extract_1(Cx1);
  const unsigned int z = extract_2(Cx1);
  const unsigned int w = extract_3(Cx1);

  bool passed = true;
  for (int i = 0; i<4; i++)
  {
    const bool b1 = (result1[i] == 1);
    const bool b2 = (result2[i] == 2);
    const bool b3 = (result3[i] == 3);
    const bool b4 = (result4[i] == 4);

    if (!b1 || !b2 || !b3 || !b4)
    {
      passed = false;
      break;
    }
  }
  return passed && (x == 1) && (y == 2) && (z == 3) && (w == 4);
}