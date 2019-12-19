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

#if __GNUC__
#define CVEX_ALIGNED(X) __attribute__((__aligned__(X)))
#elif _MSC_VER
#define CVEX_ALIGNED(X) __declspec(align(X))
#else
#error "Unsupported compiler"
#endif

#include <cmath>

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

  
  static inline vfloat4 to_float32(const vint4 a)    { return vfloat4{(float)a[0], (float)a[1], (float)a[2], (float)a[3]}; }
  static inline vfloat4 to_float32(const vuint4 a)   { return vfloat4{(float)a[0], (float)a[1], (float)a[2], (float)a[3]}; }
  
  static inline vfloat4 as_float32(const vint4 a_val)   { return reinterpret_cast<vfloat4>(a_val); }
  static inline vfloat4 as_float32(const vuint4 a_val)  { return reinterpret_cast<vfloat4>(a_val); }
  static inline vint4   as_int32  (const vfloat4 a_val) { return reinterpret_cast<vint4>(a_val);   }
  static inline vuint4  as_uint32(const vfloat4 a_val)  { return reinterpret_cast<vuint4>(a_val);  }

  // math; all basic operators should be implemented by gcc, so we don't define them here
  //
  #ifdef __x86_64
  static inline vfloat4 rcp_e(vfloat4 a)       { return _mm_rcp_ps(a); }
  #else
  static inline vfloat4 rcp_e(vfloat4 a)       { return 1.0f/a; }
  #endif

  static inline vfloat4 min  (const vfloat4 a, const vfloat4 b) { return a < b ? a : b; }
  static inline vfloat4 max  (const vfloat4 a, const vfloat4 b) { return a > b ? a : b; }
  static inline vfloat4 clamp(const vfloat4 x, const vfloat4 minVal, const vfloat4 maxVal) { return max(min(x, maxVal), minVal); }

  static inline vint4 min  (const vint4 a, const vint4 b) { return a < b ? a : b; }
  static inline vint4 max  (const vint4 a, const vint4 b) { return a > b ? a : b; }
  static inline vint4 clamp(const vint4 x, const vint4 minVal, const vint4 maxVal) { return max(min(x, maxVal), minVal); }

  static inline vuint4 min  (const vuint4 a, const vuint4 b) { return a < b ? a : b; }
  static inline vuint4 max  (const vuint4 a, const vuint4 b) { return a > b ? a : b; }
  static inline vuint4 clamp(const vuint4 x, const vuint4 minVal, const vuint4 maxVal) { return max(min(x, maxVal), minVal); }

  // convert and cast
  //
  static inline vint4   to_int32(const vfloat4 a)  { return vint4  { (int)a[0], (int)a[1], (int)a[2], (int)a[3]}; }
  static inline vint4   to_int32(const vuint4  a)  { return (vint4)a; }

  static inline vuint4  to_uint32(const vint4   a)     { return (vuint4)a; }
  static inline vuint4  to_uint32(const vfloat4 a_val) { return (vuint4)(max(to_int32(a_val),vint4{0,0,0,0})); }

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
    const _sint64_t a2 = ( *(_sint64_t*)&a ) | ( *(_sint64_t*)&a[2] );
    return (a2 != 0);
  }

  static inline bool test_bits_all(const vint4 a)
  {
    const _uint64_t* p1 = (const _uint64_t*)&a;
    const _uint64_t* p2 = p1 + 1;
    const _uint64_t a2 = (*p1) & (*p2);
    return (a2 == _uint64_t(0xFFFFFFFFFFFFFFFF));
  }

  static inline bool test_bits_any(const vuint4 a)  { return test_bits_any(reinterpret_cast<vint4>(a)); }
  static inline bool test_bits_any(const vfloat4 a) { return test_bits_any(reinterpret_cast<vint4>(a)); }
  static inline bool test_bits_all(const vuint4 a)  { return test_bits_all(reinterpret_cast<vint4>(a)); }
  static inline bool test_bits_all(const vfloat4 a) { return test_bits_all(reinterpret_cast<vint4>(a)); }

  static inline void prefetch(const float* ptr) {  __builtin_prefetch(ptr); }
  static inline void prefetch(const int* ptr)   {  __builtin_prefetch(ptr); }

  static inline vfloat4 shuffle_zyxw(vfloat4 a_src) { return __builtin_shuffle(a_src, vint4{2,1,0,3}); }
  static inline vfloat4 shuffle_yzxw(vfloat4 a_src) { return __builtin_shuffle(a_src, vint4{1,2,0,3}); }
  static inline vfloat4 shuffle_zxyw(vfloat4 a_src) { return __builtin_shuffle(a_src, vint4{2,0,1,3}); }

  static inline vfloat4 shuffle_xyxy(vfloat4 a_src) { return __builtin_shuffle(a_src, vint4{0,1,0,1});  }
  static inline vfloat4 shuffle_zwzw(vfloat4 a_src) { return __builtin_shuffle(a_src, vint4{2,3,2,3}); }

  static inline vfloat4 cross3(const vfloat4 a, const vfloat4 b) 
  {
    const vfloat4 a_yzx = shuffle_yzxw(a);
    const vfloat4 b_yzx = shuffle_yzxw(b);
    return shuffle_yzxw(a*b_yzx - a_yzx*b);
  }

  static inline vfloat4 splat_0(const vfloat4 v) { return __builtin_shuffle(v, vint4{0,0,0,0}); }
  static inline vfloat4 splat_1(const vfloat4 v) { return __builtin_shuffle(v, vint4{1,1,1,1}); }
  static inline vfloat4 splat_2(const vfloat4 v) { return __builtin_shuffle(v, vint4{2,2,2,2}); }
  static inline vfloat4 splat_3(const vfloat4 v) { return __builtin_shuffle(v, vint4{3,3,3,3}); }

  static inline vint4 splat_0(const vint4 v) { return __builtin_shuffle(v, vint4{0,0,0,0}); }
  static inline vint4 splat_1(const vint4 v) { return __builtin_shuffle(v, vint4{1,1,1,1}); }
  static inline vint4 splat_2(const vint4 v) { return __builtin_shuffle(v, vint4{2,2,2,2}); }
  static inline vint4 splat_3(const vint4 v) { return __builtin_shuffle(v, vint4{3,3,3,3}); }

  static inline vuint4 splat_0(const vuint4 v) { return __builtin_shuffle(v, vint4{0,0,0,0}); }
  static inline vuint4 splat_1(const vuint4 v) { return __builtin_shuffle(v, vint4{1,1,1,1}); }
  static inline vuint4 splat_2(const vuint4 v) { return __builtin_shuffle(v, vint4{2,2,2,2}); }
  static inline vuint4 splat_3(const vuint4 v) { return __builtin_shuffle(v, vint4{3,3,3,3}); }

  static inline int extract_0(const vint4 a_val) { return a_val[0]; }
  static inline int extract_1(const vint4 a_val) { return a_val[1]; }
  static inline int extract_2(const vint4 a_val) { return a_val[2]; }
  static inline int extract_3(const vint4 a_val) { return a_val[3]; }

  static inline unsigned int extract_0(const vuint4 a_val) { return a_val[0]; }
  static inline unsigned int extract_1(const vuint4 a_val) { return a_val[1]; }
  static inline unsigned int extract_2(const vuint4 a_val) { return a_val[2]; }
  static inline unsigned int extract_3(const vuint4 a_val) { return a_val[3]; }

  static inline float extract_0(const vfloat4 a_val) { return a_val[0]; }
  static inline float extract_1(const vfloat4 a_val) { return a_val[1]; }
  static inline float extract_2(const vfloat4 a_val) { return a_val[2]; }
  static inline float extract_3(const vfloat4 a_val) { return a_val[3]; }

  #ifdef __x86_64
  static inline float   dot3f(const vfloat4 a, const vfloat4 b) { return _mm_cvtss_f32(_mm_dp_ps(a, b, 0x7f)); }
  static inline vfloat4 dot3v(const vfloat4 a, const vfloat4 b) { return _mm_dp_ps(a, b, 0x7f); }
  static inline vfloat4 dot4v(const vfloat4 a, const vfloat4 b) { return _mm_dp_ps(a, b, 0xff); }
  static inline float   dot4f(const vfloat4 a, const vfloat4 b) { return _mm_cvtss_f32(_mm_dp_ps(a, b, 0xff)); }

  static inline float   length3f(const vfloat4 a) { return _mm_cvtss_f32(_mm_sqrt_ss(dot3v(a,a)) ); }
  static inline float   length4f(const vfloat4 a) { return _mm_cvtss_f32(_mm_sqrt_ss(dot4v(a,a)) ); }
  static inline vfloat4 length3v(const vfloat4 a) { return _mm_sqrt_ps(dot3v(a,a)); }
  static inline vfloat4 length4v(const vfloat4 a) { return _mm_sqrt_ps(dot4v(a,a)); }

  static inline vfloat4 floor(const vfloat4 a_val) { return _mm_floor_ps(a_val); }
  static inline vfloat4 ceil(const vfloat4 a_val)  { return _mm_ceil_ps(a_val);  }
  static inline void set_ftz() { _MM_SET_ROUNDING_MODE(_MM_ROUND_TOWARD_ZERO); }
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

  static inline vfloat4 length3v(const vfloat4 a) 
  {
    const vfloat4 mres = a*a;
    const float res    = sqrtf(mres[0] + mres[1] + mres[2]);
    return vfloat4{res,res,res,res}; 
  }

  static inline float   dot4f(const vfloat4 a, const vfloat4 b) 
  {
    const vfloat4 mres = a*b; 
    return mres[0] + mres[1] + mres[2] + mres[3]; 
  }

  static inline vfloat4 dot4v(const vfloat4 a, const vfloat4 b) 
  {
    const vfloat4 mres = a*b;
    const float res    = mres[0] + mres[1] + mres[2] + mres[3];
    return vfloat4{res,res,res,res}; 
  }

  static inline vfloat4 length4v(const vfloat4 a) 
  {
    const vfloat4 mres = a*a;
    const float res    = sqrtf(mres[0] + mres[1] + mres[2] + mres[3]);
    return vfloat4{res,res,res,res}; 
  }
  
  static inline float length3f(const vfloat4 a) { return sqrtf(dot3f(a,a)); }
  static inline float length4f(const vfloat4 a) { return sqrtf(dot4f(a,a)); }

  static inline vfloat4 ceil(const vfloat4 a)
  {
    const vfloat4 res = {::ceil(a[0]), ::ceil(a[1]), ::ceil(a[2]), ::ceil(a[3])};
    return res;
  }

  static inline vfloat4 floor(const vfloat4 a)
  {
    const vfloat4 res = {::floor(a[0]), ::floor(a[1]), ::floor(a[2]), ::floor(a[3])};
    return res;
  }

  inline static void set_ftz() {}
  #endif
  

  // cmpgt3
  // extract_<0,1,2,3>

  //color_compress_bgra, color_compress_rgba 

};

#endif //TEST_GL_TOP_VFLOAT4_GCC_H
