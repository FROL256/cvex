//
// Created by frol on 30.10.18.
//

#ifndef TEST_GL_TOP_VFLOAT4_GCC_H
#define TEST_GL_TOP_VFLOAT4_GCC_H

#ifdef __x86_64
  #include <xmmintrin.h> // SSE
  #include <emmintrin.h> // SSE2
  #include <smmintrin.h> // SSE4.1 
#endif

namespace cvex
{ 
  typedef unsigned           int _uint32_t;
  typedef unsigned long long int _uint64_t;
  typedef          long long int _sint64_t;

  typedef _uint32_t vuint4  __attribute__((vector_size(16)));
  typedef int       vint4   __attribute__((vector_size(16)));
  typedef float     vfloat4 __attribute__((vector_size(16)));

  typedef _uint32_t _vuint4u  __attribute__((vector_size(16), aligned(1)));
  typedef int       _vint4u   __attribute__((vector_size(16), aligned(1)));
  typedef float     _vfloat4u __attribute__((vector_size(16), aligned(1)));

  // load/store, splat ... 
  //
  static inline vuint4  load_u(const _uint32_t* p) { return *((_vuint4u*)p);  }
  static inline vint4   load_u(const int* p)       { return *((_vint4u*)p);   }
  static inline vfloat4 load_u(const float* p)     { return *((_vfloat4u*)p); }

  static inline vuint4  load  (const _uint32_t* p) { return *((vuint4*)p);  }
  static inline vint4   load  (const int* p)       { return *((vint4*)p);   }
  static inline vfloat4 load  (const float* p)     { return *((vfloat4*)p); }

  static inline void store_u(int* p,       vint4   a_val)   { *((_vint4u*)(p))   = a_val; }
  static inline void store_u(_uint32_t* p, vuint4  a_val)   { *((_vuint4u*)(p))  = a_val; }
  static inline void store_u(float* p,     vfloat4 a_val)   { *((_vfloat4u*)(p)) = a_val; }

  static inline void store(int* p,       vint4   a_val)   { *((vint4*)(p))   = a_val; }
  static inline void store(_uint32_t* p, vuint4  a_val)   { *((vuint4*)(p))  = a_val; }
  static inline void store(float* p,     vfloat4 a_val)   { *((vfloat4*)(p)) = a_val; }

  static inline vint4   splat(int x)       { return vint4  {x,x,x,x}; }
  static inline vuint4  splat(_uint32_t x) { return vuint4 {x,x,x,x}; }
  static inline vfloat4 splat(float x)     { return vfloat4{x,x,x,x}; }

  static inline vint4   make_vint  (int a, int b, int c, int d)                         { return vint4  {a,b,c,d}; } // 
  static inline vuint4  make_vuint (_uint32_t a, _uint32_t b, _uint32_t c, _uint32_t d) { return vuint4 {a,b,c,d}; } // 
  static inline vfloat4 make_vfloat(float a, float b, float c, float d)                 { return vfloat4{a,b,c,d}; } //

  // convert and cast
  //
  static inline vint4   to_int32  (vfloat4 a)  { return vint4  { (int)a[0], (int)a[1], (int)a[2], (int)a[3]}; }
  static inline vint4   to_int32  (vuint4  a)  { return (vint4)a; }

  static inline vuint4  to_uint32 (vfloat4 a)  { return vuint4 { (_uint32_t)a[0], (_uint32_t)a[1], (_uint32_t)a[2], (_uint32_t)a[3]}; }
  static inline vuint4  to_uint32 (vint4   a)  { return (vuint4)a; }
  
  static inline vfloat4 to_float32(vint4 a)    { return vfloat4{(float)a[0], (float)a[1], (float)a[2], (float)a[3]}; }
  static inline vfloat4 to_float32(vuint4 a)   { return vfloat4{(float)a[0], (float)a[1], (float)a[2], (float)a[3]}; }
  
  static inline vfloat4 as_vfloat(const vint4 a_val)  { return reinterpret_cast<vfloat4>(a_val); }
  static inline vfloat4 as_vfloat(const vuint4 a_val) { return reinterpret_cast<vfloat4>(a_val); }
  static inline vint4   as_vint (const vfloat4 a_val) { return reinterpret_cast<vint4>(a_val);   }
  static inline vuint4  as_vuint(const vfloat4 a_val) { return reinterpret_cast<vuint4>(a_val);  }

  // math; all basic operators should be implemented by gcc, so we don't define them here
  //
  #ifdef __x86_64
  static inline vfloat4 rcp_e(vfloat4 a)       { return _mm_rcp_ps(a); }
  #else
  static inline vfloat4 rcp_e(vfloat4 a)       { return 1.0f/a; }
  #endif

  static inline vfloat4 vmin  (const vfloat4 a, const vfloat4 b) { return a < b ? a : b; }
  static inline vfloat4 vmax  (const vfloat4 a, const vfloat4 b) { return a > b ? a : b; }
  static inline vfloat4 vclamp(const vfloat4 x, const vfloat4 minVal, const vfloat4 maxVal) { return vmax(vmin(x, maxVal), minVal); }

  // shuffle operations ...
  //
  static inline vint4   blend(const vint4 a,   const vint4 b,   const vint4  mask) { return ((mask & a) | (~mask & b)); }
  static inline vuint4  blend(const vuint4 a,  const vuint4 b,  const vuint4 mask) { return ((mask & a) | (~mask & b)); }
  static inline vfloat4 blend(const vfloat4 a, const vfloat4 b, const vint4  mask)
  {
    const vint4 ia = reinterpret_cast<vint4>(a);
    const vint4 ib = reinterpret_cast<vint4>(b);
    return reinterpret_cast<vfloat4>((mask & ia) | (~mask & ib));
  }

  static inline vfloat4 blend(const vfloat4 a, const vfloat4 b, const vuint4 mask)
  {
    const vuint4 ia = reinterpret_cast<vuint4>(a);
    const vuint4 ib = reinterpret_cast<vuint4>(b);
    return reinterpret_cast<vfloat4>((mask & ia) | (~mask & ib));
  }

  static inline bool test_bits_any(const vint4 a)
  {
    //return (a[0] != 0 && a[1] != 0 && a[2] != 0 && a[3] != 0);
    const _sint64_t a2 = ( *(_sint64_t*)&a ) | ( *(_sint64_t*)&a[2] );
    return (a2 != 0);
  }

  static inline bool test_bits_any(const vuint4 a)
  {
    //return (a[0] != 0 && a[1] != 0 && a[2] != 0 && a[3] != 0);
    const _uint64_t a2 = ( *(_uint64_t*)&a ) | ( *(_uint64_t*)&a[2] );
    return (a2 != 0);
  }

  static inline bool test_bits_any(const vfloat4 a) { return test_bits_any(reinterpret_cast<vuint4>(a)); }
  
  // test_bits_all (!!!)

  #ifdef __x86_64
  static void set_ftz() { _MM_SET_ROUNDING_MODE(_MM_ROUND_TOWARD_ZERO); }
  #else
  static void set_ftz() {}
  #endif

  static inline void prefetch(const float* ptr) {  __builtin_prefetch(ptr); }
  static inline void prefetch(const int* ptr)   {  __builtin_prefetch(ptr); }

  #ifdef __x86_64
  static inline float   dot3f(const vfloat4 a, const vfloat4 b) { return _mm_cvtss_f32(_mm_dp_ps(a, b, 0x7f)); }
  static inline vfloat4 dot3v(const vfloat4 a, const vfloat4 b) { return _mm_dp_ps(a, b, 0x7f); }
  #else
  static inline float   dot3f(const vfloat4 a, const vfloat4 b) 
  {
    const vfloat4 mres = a*b; 
    return mres[0] + mres[1] + mres[2]; 
  }

  static inline vfloat4 dot3v(const vfloat4 a, const vfloat4 b) 
  {
    const vfloat4 mres = a*b;
    const float res    = mres[0] + mres[1] + mres[2];
    return vfloat4{res,res,res,res}; 
  }

  #endif

  // cross3
  // length3
  // cmpgt3

  // extract_<0,1,2,3>

  // shuffle2_xy_xy, shuffle2_xy_zw, shuffle2_zw_zw ?
  
  // add_s, subb_s, ... ?

  //color_compress_bgra, color_compress_rgba 

};

#endif //TEST_GL_TOP_VFLOAT4_GCC_H
