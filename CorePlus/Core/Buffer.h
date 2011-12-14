#ifndef CORE_BUFFER_H
#define CORE_BUFFER_H
#include "Type.h"


namespace System{

	//  ������Ԫ���͵����顣
	singleton class  Buffer{
	public:

		// ��ָ����Ŀ���ֽڴ���ʼ���ض�ƫ������Դ���鸴�Ƶ���ʼ���ض�ƫ������Ŀ�����顣
		template<class T>
		static inline void BlockCopy(const T* src, int srcOffset, T* dst, int dstOffset, int count){
			memcpy(dst + dstOffset, src + srcOffset, sizeof(T) * count);
		}

		// ��ָ����Ŀ���ֽڴ���ʼ���ض�ƫ������Դ���鸴�Ƶ���ʼ���ض�ƫ������Ŀ�����顣
		template<class T>
		static inline void BlockCopy(const T* src, T* dst, int count){
			memcpy(dst, src, sizeof(T) * count);
		}

		// ��ָ����Ŀ���ֽڴ���ʼ���ض�ƫ������Դ�����ƶ�����ʼ���ض�ƫ������Ŀ�����顣
		template<class T>
		static inline void BlockMove(const T* src, int srcOffset, T* dst, int dstOffset, int count){
			memmove(dst + dstOffset, src + srcOffset, sizeof(T) * count);
		}

		// ��ָ����Ŀ���ֽڴ���ʼ���ض�ƫ������Դ�����ƶ�����ʼ���ض�ƫ������Ŀ�����顣
		template<class T>
		static inline void BlockMove(const T* src, T* dst, int count){
			memmove(dst, src, sizeof(T) * count);
		}

		// �� Array �е�һϵ��Ԫ������Ϊ�㡢false �� NULL ָ�룬����ȡ����Ԫ�����͡�
		template<class T>
		static inline void Clear(T* array, int count){
			memset(array, 0, sizeof(T) * count);
		}

	};

}


#endif