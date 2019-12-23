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
    float4() : x(0), y(0), z(0), w(0) {}
    float4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
    explicit float4(float a[4]) : x(a[0]), y(a[1]), z(a[2]), w(a[3]) {}

    float4(cvex::vfloat4 rhs) { v = rhs; }
    float4 operator=(cvex::vfloat4 rhs) { v = rhs; return *this; }
    inline operator cvex::vfloat4() const { return v; }
    
    float& operator[](int i)       { return v[i]; }
    float  operator[](int i) const { return v[i]; }

    inline float4 operator+(const float4& rhs) const { return v + rhs.v; }
    inline float4 operator-(const float4& rhs) const { return v - rhs.v; }
    inline float4 operator*(const float4& rhs) const { return v * rhs.v; }
    inline float4 operator/(const float4& rhs) const { return v / rhs.v; }

    inline float4 operator+(const float rhs) const { return v + rhs; }
    inline float4 operator-(const float rhs) const { return v - rhs; }
    inline float4 operator*(const float rhs) const { return v * rhs; }
    inline float4 operator/(const float rhs) const { return v / rhs; }

    union
    {
      struct {float x, y, z, w; };
      cvex::vfloat4 v;
    };
  };

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

};



#endif
