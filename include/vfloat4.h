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

#endif
