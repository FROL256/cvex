#ifndef VFLOAT4_ALL_H
#define VFLOAT4_ALL_H

// This is just and example. 
// In practise you may take any of these files that you prefer for your platform.  
// Or customise this file as you like.

#ifdef WIN32
  #include "vfloat4_x64.h"
#else
  #ifdef __arm__
    #include "vfloat4_arm.h"
  #else
    #include "vfloat4_gcc.h"
  #endif  
#endif 

// __mips__
// __ppc__ 

#include "LiteMath.h"

namespace cmath
{
  typedef LiteMath::float2 float2;
  typedef LiteMath::float3 float3;
  
  typedef cvex::vint4     int4;
  typedef cvex::vuint4    uint4;

  struct float4
  {
    inline float4() : x(0), y(0), z(0), w(0) {}
    inline float4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
    inline explicit float4(float a[4]) : x(a[0]), y(a[1]), z(a[2]), w(a[3]) {}

    inline float4(cvex::vfloat4 rhs) { v = rhs; }
    inline float4 operator=(cvex::vfloat4 rhs) { v = rhs; return *this; }
    inline operator cvex::vfloat4() const { return v; }
    
    inline float& operator[](int i)       { return v[i]; }
    inline float  operator[](int i) const { return v[i]; }

    union
    {
      struct {float x, y, z, w; };
      cvex::vfloat4 v;
    };
  };

  #ifndef WIN32

  inline float4 operator+(const float4& a, const float4& b) { return a.v + b.v; }
  inline float4 operator-(const float4& a, const float4& b) { return a.v - b.v; }
  inline float4 operator*(const float4& a, const float4& b) { return a.v * b.v; }
  inline float4 operator/(const float4& a, const float4& b) { return a.v / b.v; }

  inline float4 operator+(const float4& a, const float rhs) { return a.v + rhs; }
  inline float4 operator-(const float4& a, const float rhs) { return a.v - rhs; }
  inline float4 operator*(const float4& a, const float rhs) { return a.v * rhs; }
  inline float4 operator/(const float4& a, const float rhs) { return a.v / rhs; }

  inline float4 operator+(const float c, float4 v) { return c + v.v; }
  inline float4 operator-(const float c, float4 v) { return c - v.v; }
  inline float4 operator*(const float c, float4 v) { return c * v.v; }
  inline float4 operator/(const float c, float4 v) { return c / v.v; }

  inline cvex::vint4 operator> (const float4& a, const float4& b) { return (a.v > b.v) ; }
  inline cvex::vint4 operator< (const float4& a, const float4& b) { return (a.v < b.v) ; }
  inline cvex::vint4 operator>=(const float4& a, const float4& b) { return (a.v >= b.v); }
  inline cvex::vint4 operator<=(const float4& a, const float4& b) { return (a.v <= b.v); }
  inline cvex::vint4 operator==(const float4& a, const float4& b) { return (a.v == b.v); }
  inline cvex::vint4 operator!=(const float4& a, const float4& b) { return (a.v != b.v); }

  #endif

  /**
  \brief this class use colmajor memory layout for effitient vector-matrix operations
  */
  struct float4x4
  {
    float4x4() {}
    float4x4(const float A[16])
    {
      m_col[0] = float4{ A[0], A[4], A[8], A[12] };
      m_col[1] = float4{ A[1], A[5], A[9], A[13] };
      m_col[2] = float4{ A[2], A[6], A[10], A[14] };
      m_col[3] = float4{ A[3], A[7], A[11], A[15] };
    }

    inline float4x4 operator*(const float4x4& rhs)
    {
      float4x4 res;
      //mat4_mul_mat4((float*)res.m_col, (const float*)m_col, (const float*)rhs.m_col);
      cvex::mat4_rowmajor_mul_mat4((float*)res.m_col, (const float*)rhs.m_col, (const float*)m_col); // transpose chenge multiplication order (due to in fact we use colmajor)
      return res;
    }

    inline float4 get_col(int i) const { return m_col[i]; }
    inline void   set_col(int i, float4 a_col) { m_col[i] = a_col; }

    inline float4 get_row(int i) const { return float4{ m_col[0][i], m_col[1][i], m_col[2][i], m_col[3][i] }; }
    inline void   set_row(int i, float4 a_col)
    {
      m_col[0][i] = a_col[0];
      m_col[1][i] = a_col[1];
      m_col[2][i] = a_col[2];
      m_col[3][i] = a_col[3];
    }

  private:
    float4 m_col[4];
  };

  static inline float4 operator*(const float4x4& m, const float4& v)
  {
    float4 res;
    cvex::mat4_colmajor_mul_vec4((float*)&res, (const float*)&m, (const float*)&v);
    return res;
  }

  static inline float4x4 transpose(const float4x4& rhs)
  {
    float4x4 res;
    transpose4((const cvex::vfloat4*)&rhs, (cvex::vfloat4*)&res);
    return res;
  }

};

#endif
