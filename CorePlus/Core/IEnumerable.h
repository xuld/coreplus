#ifndef CORE_IENUMERABLE_H
#define CORE_IENUMERABLE_H

#include "IEnumerator.h"

namespace System {

	namespace Collections {

		// 公开枚举数，该枚举数支持在非泛型集合上进行简单迭代。
		template<typename T>
		class IEnumerable {

		public:

			// 返回一个循环访问集合的枚举数。
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
