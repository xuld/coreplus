#ifndef CORE_IENUMERATOR_H
#define CORE_IENUMERATOR_H
#include "Type.h"


namespace System{

	namespace Collections {

		// ֧�ֶԷǷ��ͼ��ϵļ򵥵�����
		template<typename T>
		abstract class IEnumerator {


		public:
			 
			// ��ö�����ƽ������ϵ���һ��Ԫ�ء�
			virtual bool MoveNext() = 0;

			// ��ö��������Ϊ���ʼλ�ã���λ��λ�ڼ����е�һ��Ԫ��֮ǰ��
			virtual void Reset() = 0;

			// ��ȡ�����еĵ�ǰԪ�ء�
			virtual const T& GetCurrent() = 0;

			// ��ȡ�����еĵ�ǰԪ�ء�
			propertyGet(const T&, Current);
		};

	}
}


#endif