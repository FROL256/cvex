#include <iostream>
#include <cmath>
#include <cstring>

#include "include/lite_math.h"
#include "LiteMath.h"

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
  
  litemath::float4x4 m1(initData);
  litemath::float4x4 m2(initData2);
  litemath::float4   v1 = {1.0f, 2.0f, 3.0f, 4.0f};

  litemath::float4x4 res_mm = m1*m2;
  litemath::float4   res_mv = m1*v1;

  litemath::float4x4 res_mm_t = transpose(res_mm);
  
  //
  //
  litemath::float4 test1 = m1.get_row(0); litemath::float4 test3 = {1.0f, 2.0f, 3.0f, 4.0f};
  litemath::float4 test2 = m1.get_col(0); litemath::float4 test5 = {1.0f, 5.0f, 9.0f, 13.0f};

  m1.set_col(1, litemath::float4{0.0f, 0.0f, 0.0f, 0.0f});
  m1.set_row(2, litemath::float4{1.1f, 1.0f, 1.0f, 1.0f});

  float initData3[16] = {1.0f, 0.0f, 3.0f, 4.0f,
                         5.0f, 0.0f, 7.0f, 8.0f,
                         1.1f, 1.0f, 1.0f, 1.0f,
                         13.0f,0.0f, 15.0f, 16.0f
  };
  litemath::float4x4 m3(initData3);

  //
  //
  const bool b1 = (memcmp(&ref_mm, &res_mm_t, sizeof(litemath::float4x4)) == 0);
  const bool b2 = (memcmp(&ref_mv, &res_mv,   sizeof(litemath::float4))   == 0);
  const bool b3 = (memcmp(&test1,  &test3,    sizeof(litemath::float4))   == 0);
  const bool b4 = (memcmp(&test2,  &test5,    sizeof(litemath::float4))   == 0);
  const bool b5 = (memcmp(&m1,     &m3,       sizeof(litemath::float4x4)) == 0);
  
  return b1 && b2 && b3 && b4 && b5;
}

bool vf4_test036_matrixinv()
{
  float initData[16] = {1.0f, -2.0f, 3.0f, 4.0f,
                        5.0f, 6.0f, -7.0f, 8.0f,
                        9.0f, -10.0f,11.0f,12.0f,
                        -13.0f, 14.0f, 15.0f, 16.0f
  };

  LiteMath::float4x4 testMatrix(initData);
  LiteMath::float4x4 testMatrixInv = LiteMath::inverse4x4(testMatrix);
  LiteMath::float4x4 testRes       = LiteMath::mul(testMatrix,testMatrixInv);

  litemath::float4x4 m1(initData);
  litemath::float4x4 m2 = litemath::inverse4x4(m1);
  litemath::float4x4 m3 = m1*m2;

  const bool row1 = (fabs(m3(0,0) - 1.0f) < litemath::EPSILON) && (fabs(m3(0,1)       ) < litemath::EPSILON) && (fabs(m3(0,2)       ) < litemath::EPSILON) && (fabs(m3(0,3)       ) < litemath::EPSILON);
  const bool row2 = (fabs(m3(1,0)       ) < litemath::EPSILON) && (fabs(m3(1,1) - 1.0f) < litemath::EPSILON) && (fabs(m3(1,2)       ) < litemath::EPSILON) && (fabs(m3(1,3)       ) < litemath::EPSILON);
  const bool row3 = (fabs(m3(2,0)       ) < litemath::EPSILON) && (fabs(m3(2,1)       ) < litemath::EPSILON) && (fabs(m3(2,2) - 1.0f) < litemath::EPSILON) && (fabs(m3(2,3)       ) < litemath::EPSILON);
  const bool row4 = (fabs(m3(3,0)       ) < litemath::EPSILON) && (fabs(m3(3,1)       ) < litemath::EPSILON) && (fabs(m3(3,2)       ) < litemath::EPSILON) && (fabs(m3(3,3) - 1.0f) < litemath::EPSILON);

  return row1 && row2 && row3 && row4;
}
