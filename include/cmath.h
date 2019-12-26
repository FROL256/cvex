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
  
  typedef cvex::vfloat4x4 float4x4;
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

};

#endif
