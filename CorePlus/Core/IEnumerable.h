#ifndef CORE_IENUMERABLE_H
#define CORE_IENUMERABLE_H

#include "IEnumerator.h"

namespace System {

	namespace Collections {

		// ����ö��������ö����֧���ڷǷ��ͼ����Ͻ��м򵥵�����
		template<typename T>
		class IEnumerable {

		public:

			// ����һ��ѭ�����ʼ��ϵ�ö������
			virtual __gc  IEnumerator<T> *GetEnumerator() = 0;
	
			//inline void ForEach(Delegate<T&>& func)
			//{
			//	/*Handle<IEnumerator<T> > iter = GetEnumerator();
			//	while(iter->Next())
			//	{
			//		func.Call(iter->GetCurrent());
			//	}*/
			//}

		};

	}

}

#endif
