#ifndef CORE_BUFFER_H
#define CORE_BUFFER_H
#include "Type.h"


namespace System{

	//  操作基元类型的数组。
	singleton class  Buffer{
	public:

		// 将指定数目的字节从起始于特定偏移量的源数组复制到起始于特定偏移量的目标数组。
		template<class T>
		static inline void BlockCopy(const T* src, int srcOffset, T* dst, int dstOffset, int count){
			memcpy(dst + dstOffset, src + srcOffset, sizeof(T) * count);
		}

		// 将指定数目的字节从起始于特定偏移量的源数组复制到起始于特定偏移量的目标数组。
		template<class T>
		static inline void BlockCopy(const T* src, T* dst, int count){
			memcpy(dst, src, sizeof(T) * count);
		}

		// 将指定数目的字节从起始于特定偏移量的源数组移动到起始于特定偏移量的目标数组。
		template<class T>
		static inline void BlockMove(const T* src, int srcOffset, T* dst, int dstOffset, int count){
			memmove(dst + dstOffset, src + srcOffset, sizeof(T) * count);
		}

		// 将指定数目的字节从起始于特定偏移量的源数组移动到起始于特定偏移量的目标数组。
		template<class T>
		static inline void BlockMove(const T* src, T* dst, int count){
			memmove(dst, src, sizeof(T) * count);
		}

		// 将 Array 中的一系列元素设置为零、false 或 NULL 指针，具体取决于元素类型。
		template<class T>
		static inline void Clear(T* array, int count){
			memset(array, 0, sizeof(T) * count);
		}

	};

}


#endif