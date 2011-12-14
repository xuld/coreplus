#ifndef COREPLUS_CORE_H
#define COREPLUS_CORE_H


#include"Config.h"


// ȫ��Ŀ��ʼ


/*
�����ĺ궨��(���ֺ��ɱ���������)


ƽ̨:

	SYSTEM_PLATFORM_WIN - Windows
	SYSTEM_PLATFORM_WIN32 - 32λWindows
	SYSTEM_PLATFORM_WIN64 - 64λWindows
	SYSTEM_PLATFORM_WINCE - Windows CE

	SYSTEM_PLATFORM_OSX - Macintosh OS X  (Cocoa Objective-C  ��)

	SYSTEM_PLATFORM_POSIX - �� Unix  (Linux)


���뻷��:

	SYSTEM_PLATFORM_64 - 64λ
	SYSTEM_PLATFORM_32 - 32λ


������:

	SYSTEM_COMPLIER_NAME - ����������

	SYSTEM_COMPILER_CYGWIN - Cygwin

	SYSTEM_COMPLIER_ICL - Ӣ�ض� C++ ������

	SYSTEM_COMPLIER_VC - ΢�� Visual C++ ������
		= 0
		= 5
		= 6
		= 7
		= 8
		= 9
		= 10

	SYSTEM_COMPLIER_DMC - Digital Mar C++ ������

	SYSTEM_COMPLIER_BCC - Borland C++ ������
		= 4
		= 5
		= 6
		= 7
		= 8

	SYSTEM_COMPLIER_CW - CodeWarrior MetroWerks C++ ������
		= 6
	SYSTEM_COMPLIER_CW_OSX
	SYSTEM_COMPLIER_CW_W32

	SYSTEM_COMPLIER_GCC - GCC C++ ������

	SYSTEM_COMPLIER_MINGW -  MinGW ������

����:

	LIT64 - ����  int64 ���͵ı���

	CCHAR - ���� const char ���͵ı���

����:

	SYSTEM_UNICODE - Ĭ��ʹ�� Unicode ����

	SYSTEM_DEBUG - �Ƿ����õ���

	SYSTEM_TRACE - �Ƿ��������

	STSREM_THREADS - �Ƿ����ö��߳�

����:

	SYSTEM_USING_INCLUDE - ������

	SYSTEM_USING_EXPORT - ������

	SYSTEM_USING_IMPORT - �����

	SYSTEM_USING_DLL - ���� DLL


*/

#pragma region ����


#pragma region ����ϵͳ

#if defined(WIN32) || defined(_WIN32) || defined(_WIN32_WCE)
	#define SYSTEM_PLATFORM_WIN32
#endif

#if defined(WIN64) || defined(_WIN64)
#define SYSTEM_PLATFORM_WIN64
#endif

#if defined(_WIN32_WCE)
#define SYSTEM_PLATFORM_WINCE
#endif

#if defined(SYSTEM_PLATFORM_WIN32) || defined(SYSTEM_PLATFORM_WIN64)
	#define SYSTEM_PLATFORM_WIN
#endif

#ifdef OSX
	#define SYSTEM_PLATFORM_OSX
#endif

#if defined(__linux__) || defined(i386) || defined(__i386__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
    #define SYSTEM_PLATFORM_POSIX
#endif

#pragma endregion

#pragma region λ��

/*
 ====================================================================
                      char   short  int   long   long long   pointer
 ====================================================================
  LP32: Win16         8      16     16    32                 32
 ILP64: Cray, ETA     8      16     64    64                 64
 --------------------------------------------------------------------

 ILP32: Win32,Linux,  8      16     32    32                 32
        Solaris, HP,
        MacOS

 LLP64: Win64         8      16     32    32                 64

 LP64: most UNIXes:  8      16     32    64     64          64
 Solaris, AIX,
 HP, Linux,
 MacOS
 ====================================================================
*/
#if defined(SYSTEM_PLATFORM_WIN64) || defined(__LP64__) || defined(_LP64) || defined(__WATCOM_INT64__)
    // LLP64 �� LP64
    #define SYSTEM_PLATFORM_64
#else
    // ILP32
    #define SYSTEM_PLATFORM_32
#endif

#pragma endregion

#pragma region ������

#define SYSTEM_COMPLIER_NAME	""

#ifdef __CYGWIN__
	#define SYSTEM_COMPILER_CYGWIN 1
	#undef SYSTEM_COMPLIER_NAME
	#define SYSTEM_COMPLIER_NAME "CYGWIN"
#else
	#define SYSTEM_COMPILER_CYGWIN 0
#endif

#ifdef __INTEL_COMPILER
	#define SYSTEM_COMPLIER_ICL 1

	#define SYSTEM_COMPLIER_NAME	"ICL"
#else
	#define SYSTEM_COMPLIER_ICL 0
#endif

// Ӣ�ض������������� _MSC_VER ��ʵ�ּ��ݡ�  
#if defined(_MSC_VER) && !SYSTEM_COMPLIER_ICL

	#undef SYSTEM_COMPLIER_NAME


	#if (_MSC_VER >= 1600)
		#define SYSTEM_COMPLIER_VC 10
		#define SYSTEM_COMPLIER_NAME	"VC10.0 (VS 2010)"	
	#elif (_MSC_VER >= 1500)
		#define SYSTEM_COMPLIER_VC 9
		#define SYSTEM_COMPLIER_NAME	"VC9.0 (VS 2008)"
	#elif (_MSC_VER >= 1400)
		#define SYSTEM_COMPLIER_VC 8
		#define SYSTEM_COMPLIER_NAME	"VC8.0 (VS 2005)"
	#elif (_MSC_VER >= 1300)
		#define SYSTEM_COMPLIER_VC 7
		#define SYSTEM_COMPLIER_NAME	"VC7.0 (VS 2003)"
	#elif (_MSC_VER >= 1200)
		#define SYSTEM_COMPLIER_VC 6
		#define SYSTEM_COMPLIER_NAME	"VC6.0 (VS 2001)"
	#elif (_MSC_VER >= 1100)
		#define SYSTEM_COMPLIER_VC 5
		#define SYSTEM_COMPLIER_NAME	"VC5.0"
	#else
		#define SYSTEM_COMPLIER_VC 1
		#define SYSTEM_COMPLIER_NAME	"VC"
	#endif

    // ȡ��һЩ����

	////ȡ������: 255 �ַ����Է�
	//#pragma warning (disable : 4786)

	////ȡ������: ��ģ���ʼ��ǰʹ�á�
	//#pragma warning (disable : 4231)

	////ȡ������: ��ʶ�����ֹ���
	//#pragma warning (disable:4503)

	////ȡ������: C++ �쳣������
	//#pragma warning (disable : 4290)

	////Visual Studio .NET
	////ȡ������:  '<' : �з�/�޷� ���Ƚ�
	//#pragma warning ( disable : 4018 )

	////ȡ������: �޷������е�Ŀ '-' ���㣬 ���ؽ����Ȼ���޷���
	//#pragma warning ( disable : 4146 )

	////ȡ������:  '=' : �� 'const double' ת�� 'long', ���ܶ�ʧ����
	//#pragma warning ( disable : 4244 )

	////ȡ������: �Ǳ�׼����չ : �� for �������е�ѭ���� 'i' ������������á�
	//#pragma warning ( disable : 4288 )

	////ȡ������:  C++ �쳣�����ӡ�
	//#pragma warning ( disable : 4290 )



	////#if SYSTEM_COMPLIER_VC == 8 || SYSTEM_COMPLIER_VC == 9

	////	//ȡ������:�ѹ��ڡ�
	////	#pragma warning (disable : 4996)
	////	#ifndef _CRT_SECURE_NO_DEPRECATE
	////		#define _CRT_SECURE_NO_DEPRECATE 1
	////	#endif
	////	#ifndef _CRT_NONSTDC_NO_DEPRECATE
	////		#define _CRT_NONSTDC_NO_DEPRECATE 1
	////	#endif
	////#endif

	//#if ( _MSC_VER < 1300 )
	////ȡ������: ����δʹ�� __declspec(dllexport) ����
	//#pragma warning (disable : 4251)

	////ȡ������: ���������δ��������ĳ�Ա
	//#pragma warning (disable : 4275)
	//#endif


#else
	#define SYSTEM_COMPLIER_VC 0
#endif


#ifdef __DMC__
	#define SYSTEM_COMPLIER_DMC 1

	#undef SYSTEM_COMPLIER_NAME
	#define SYSTEM_COMPLIER_NAME	"DMC"
#else
	#define SYSTEM_COMPLIER_DMC 0
#endif


#ifdef __BORLANDC__
	#undef SYSTEM_COMPLIER_NAME

	#if (__BORLANDC__ >= 0x0580 )
		#define SYSTEM_COMPLIER_BCC 8
		#define SYSTEM_COMPLIER_NAME	"BCC8 (BDS 2006)"
	#elif (__BORLANDC__ == 0x0570)
		#define SYSTEM_COMPLIER_BCC 7
		#define SYSTEM_COMPLIER_NAME	"BCC7 (BCCKLX)"
	#elif (__BORLANDC__ >= 0x0560) && (__BORLANDC__ < 0x0570)
		#define SYSTEM_COMPLIER_BCC 6
		#define SYSTEM_COMPLIER_NAME	"BCC6"
	#elif (__BORLANDC__ >= 0x0550) && (__BORLANDC__ < 0x0560)
		#define SYSTEM_COMPLIER_BCC 5
		#define SYSTEM_COMPLIER_NAME	"BCC5"
	#elif (__BORLANDC__ >= 0x0540)
		#define SYSTEM_COMPLIER_BCC 4
		#define SYSTEM_COMPLIER_NAME	"BCC4"
	#else
		#define SYSTEM_COMPLIER_BCC 1
		#define SYSTEM_COMPLIER_NAME	"BCC"
	#endif //bcc version

	#if SYSTEM_COMPLIER_BCC == 6 && !defined(_USE_OLD_RW_STL)
		#define __MINMAX_DEFINED
		#define NOMINMAX    
		using std::min;
		using std::max;
		#define __max max
		#define __min min
	#endif

	//ȥ������
	/*#pragma warn -8026
	#pragma warn -inl
	#pragma warn -aus
	#pragma warn -ccc
	#pragma warn -csu
	#pragma warn -osh
	#pragma warn -par
	#pragma warn -pia
	#pragma warn -rch
	#pragma warn -rng
	#pragma warn -hid
	#if (__BORLANDC__ > 0x0551)
		#pragma warn -8098
	#endif	
	#pragma warn -ngu
	#pragma warn -lin*/
#else
	#define SYSTEM_COMPLIER_BCC 0
#endif


#ifdef __MWERKS__
	#define SYSTEM_COMPLIER_CW 1

	#undef SYSTEM_COMPLIER_NAME
	#if (__MWERKS__ == 0x2400)
		#define SYSTEM_COMPLIER_CW 6
		#define SYSTEM_COMPLIER_NAME	"CW6"
	#else
		#define SYSTEM_COMPLIER_CW 1
		#define SYSTEM_COMPLIER_NAME	"CW"
	#endif
#else
	#define SYSTEM_COMPLIER_CW 0
#endif


#ifdef __GNUC__
	#define SYSTEM_COMPLIER_GCC __GNUC__
	
	#undef SYSTEM_COMPLIER_NAME
	#define SYSTEM_COMPLIER_NAME "GCC"
#else
	#define SYSTEM_COMPLIER_GCC 0
#endif


#ifdef __MINGW32__
	#define SYSTEM_COMPLIER_MINGW 1

	#undef SYSTEM_COMPLIER_NAME
	#define SYSTEM_COMPLIER_NAME	"MINGW"
#else
	#define SYSTEM_COMPLIER_MINGW 0
#endif


#pragma endregion

#pragma region ����


#if defined(_UNICODE) || defined(UNICODE)
	#define SYSTEM_UNICODE	
#endif


// �� __w64 ���� ��д��С���� MSVC �£� ʹ�� /Wp64 ����Ч��
#ifndef _W64
	#if SYSTEM_COMPLIER_VC && _MSC_VER >= 1300
		#define _W64 __w64
	#else
		#define _W64
	#endif
#endif


#pragma endregion


#pragma endregion

#pragma region ����


#pragma region  ����

#if SYSTEM_COMPLIER_VC
	#define propertyGetSet(type, name)  __declspec(property(get=Get##name, put=Set##name)) type  name
	#define propertyGet(type, name)     __declspec(property(get=Get##name)) type name
	#define propertySet(type, name)     __declspec(property(put=Set##name)) type name
	#define	propertyIs(name)		__declspec(property(get=Is##name)) bool name
#elif SYSTEM_COMPLIER_BCC
	#define propertyGetSet(type, name)  __property(read=Get##name, write=Set##name)) type name
	#define propertyGet(type, name)     __property(read=Get##name)) type name
	#define propertySet(type, name)	    __property(write=Set##name)) type name
	#define propertyIs(name)     __property(read=Is##name)) bool name
#else
	
	// ��֧��

	#define propertyGetSet(type, name)
	#define propertyGet(type, name)
	#define propertySet(type, name)
	#define propertyIs(name)
#endif

#pragma endregion

#pragma endregion

#pragma region �����Ķ���

#define override  virtual   // ��ʾ����
#define abstract            // ��ʾ����
#define sealed              // ��ʾ���ɼ̳�
#define singleton           // ��ʾ��������̬�ࣩ

#define __gc                // ��ʾ�û���Ҫ�Դ˶�������ֶ���Դ�ͷ�

#ifndef __out
	#define __out
#endif

#ifndef __in
#define __in
#endif

#ifndef __ref
	#define __ref
#endif


#pragma endregion

#pragma region ϵͳ����

#if defined(_DEBUG) ||  defined(DEBUG) || defined(__DEBUG)
	#define SYSTEM_DEBUG
#endif

#if defined(_TRACE) ||  defined(TRACE) || defined(__TRACE)
	#define SYSTEM_TRACE
#endif

// ��Щ��������Ҫ�ֶ�ָ��������( ��β׺ LL )
// �÷�: uint64 x = LIT64(0xffffffffffffffff);
#if SYSTEM_COMPLIER_VC || SYSTEM_COMPLIER_BCC != 8 || SYSTEM_COMPLIER_ICL
	#define LIT64(x) x
#else
	#define LIT64(x) x##LL
#endif

// ���������ַ�
#if SYSTEM_COMPLIER_GCC || SYSTEM_COMPLIER_BCC
	#define CCHAR(x) (uint32) x
#else
	#define CCHAR(x) x
#endif

#pragma endregion

#pragma region ���뵼��


#ifdef SYSTEM_USING_DLL
	#define SYSTEM_USING_EXPORT
#endif

#if !defined(SYSTEM_USING_INCLUDE) &&  !defined(SYSTEM_USING_EXPORT) & !defined(SYSTEM_USING_IMPORT)
	#define SYSTEM_USING_IMPORT
#endif



#ifndef API
#ifdef SYSTEM_USING_INCLUDE
	#define API
#elif defined(SYSTEM_USING_EXPORT)
	#if SYSTEM_COMPLIER_MINGW || SYSTEM_COMPLIER_VC
		#define API __declspec(dllexport)
	#else
		#define API extern __declspec(dllexport)
	#endif

#else
	#if SYSTEM_COMPLIER_MINGW
		#define API
	#else
		#define API __declspec(dllimport)
	#endif

#endif
#endif

#pragma endregion




#endif