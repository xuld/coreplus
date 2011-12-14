#ifndef COREPLUS_TYPE_H
#define COREPLUS_TYPE_H
#include <tchar.h>
#include <Windows.h>
#include "Core.h"
#include "Thrower.h"

#pragma region 系统类型

namespace System{


/*
 ====================================================================
     name     orginal C++     size     equals C#                     
 ====================================================================
  int/int32       int          32         int
  short/int16     short        16         short
  int64     __int64/long long  64         long
  byte          unsigned char   8         byte
  sbyte         signed char     8         sbyte
  ushort/uint16 unsigned short 16         ushort
  uint/uint32    unsigned int  32         uint
  ulong/uint64unsigned __int64 64         ulong
  bool			  bool          8         bool
  char			  char          8		  
  uchar           uchar         8
  wchar			  TCHAR        16         char
  intptr          int64        64         IntPtr
  uintptr         uint64       64         UIntPtr
  string		const char*               string
 ====================================================================
*/


	typedef int					int32;
	typedef unsigned int		uint;
	typedef unsigned int		uint32;

	typedef short				int16;
	typedef unsigned short		ushort;
	typedef unsigned short		uint16;

#if SYSTEM_COMPLIER_VC || SYSTEM_COMPLIER_BCC || SYSTEM_COMPLIER_ICL
	typedef __int64 int64;
	typedef unsigned __int64 ulong;
	typedef unsigned __int64 uint64;
#else
	typedef unsigned long long int64;
	typedef unsigned long long ulong;
	typedef unsigned long long uint64;
#endif

	typedef unsigned char		byte;
	typedef signed char			sbyte;

	typedef unsigned char		uchar;
	typedef const char*			cstr;
	typedef const wchar_t*		wcstr;  //若编译错误，则需要在VC工程属性中打开wchar_t的内置类型支持
	typedef wchar_t				wchar;

#if SYSTEM_PLATFORM_64
	typedef int64				intptr;
	typedef uint64				uintptr;
#else
	typedef _W64 int32			intptr;
	typedef _W64 uint32			uintptr;
#endif

	typedef const TCHAR*			string;  

};


#pragma endregion

#endif