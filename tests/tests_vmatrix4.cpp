#include <iostream>
#include <cmath>
#include <cstring>

#include "include/cmath.h"


bool vf4_test035_matrixmul()
{
  float initData[16] = {1.0f, 2.0f, 3.0f, 4.0f,
                        5.0f, 6.0f, 7.0f, 8.0f,
                        9.0f, 10.0f,11.0f,12.0f,
                        13.0f, 14.0f, 15.0f, 16.0f
  };

  float initData2[16] = {-1.0f, 2.0f, 3.0f, -4.0f,
                         5.0f, -6.0f, -7.0f, 8.0f,
                         -9.0f, 10.0f,11.0f,-12.0f,
                         13.0f, -14.0f, -15.0f, 16.0f
  };

  LiteMath::float4x4 testMatrix(initData);
  LiteMath::float4x4 testMatrix2(initData2);

  LiteMath::float4   testVec = {1.0f, 2.0f, 3.0f, 4.0f};

  LiteMath::float4x4 ref_mm = LiteMath::mul(testMatrix,testMatrix2); 
  LiteMath::float4   ref_mv = LiteMath::mul(testMatrix,testVec); 
  
  cmath::float4x4 m1(initData);
  cmath::float4x4 m2(initData2);
  cmath::float4   v1 = {1.0f, 2.0f, 3.0f, 4.0f};

  cmath::float4x4 res_mm = m1*m2;
  cmath::float4   res_mv = m1*v1;

  cmath::float4x4 res_mm_t = cvex::transpose(res_mm);
  
  //
  //
  cmath::float4 test1 = m1.get_row(0); cmath::float4 test3 = {1.0f, 2.0f, 3.0f, 4.0f};
  cmath::float4 test2 = m1.get_col(0); cmath::float4 test5 = {1.0f, 5.0f, 9.0f, 13.0f};

  m1.set_col(1, cmath::float4{0.0f, 0.0f, 0.0f, 0.0f});
  m1.set_row(2, cmath::float4{1.1f, 1.0f, 1.0f, 1.0f});

  float initData3[16] = {1.0f, 0.0f, 3.0f, 4.0f,
                         5.0f, 0.0f, 7.0f, 8.0f,
                         1.1f, 1.0f, 1.0f, 1.0f,
                         13.0f,0.0f, 15.0f, 16.0f
  };
  cmath::float4x4 m3(initData3);

  //
  //
  const bool b1 = (memcmp(&ref_mm, &res_mm_t, sizeof(cmath::float4x4)) == 0);
  const bool b2 = (memcmp(&ref_mv, &res_mv, sizeof(cmath::float4))   == 0);

  const bool b3 = (memcmp(&test1, &test3, sizeof(cmath::float4))   == 0);
  const bool b4 = (memcmp(&test2, &test5, sizeof(cmath::float4))   == 0);

  const bool b5 = (memcmp(&m1, &m3, sizeof(cmath::float4x4)) == 0);
  
  return b1 && b2 && b3 && b4 && b5;
}