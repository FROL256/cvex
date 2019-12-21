#include <iostream>
#include <cmath>
#include <cstring>

#include "include/vfloat4.h"
#include "include/LiteMath.h"


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
  
  cvex::vfloat4x4 m1(initData);
  cvex::vfloat4x4 m2(initData2);
  cvex::vfloat4   v1 = {1.0f, 2.0f, 3.0f, 4.0f};

  cvex::vfloat4x4 res_mm = m1*m2;
  cvex::vfloat4   res_mv = m1*v1;

  return (memcmp(&ref_mm, &res_mm, sizeof(cvex::vfloat4x4)) == 0) && (memcmp(&ref_mv, &res_mv, sizeof(cvex::vfloat4)) == 0);
}