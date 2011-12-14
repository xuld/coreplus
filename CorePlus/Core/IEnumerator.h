#ifndef CORE_IENUMERATOR_H
#define CORE_IENUMERATOR_H
#include "Type.h"


namespace System{

	namespace Collections {

		// 支持对非泛型集合的简单迭代。
		template<typename T>
		abstract class IEnumerator {


		public:
			 
			// 将枚举数推进到集合的下一个元素。
			virtual bool MoveNext() = 0;

			// 将枚举数设置为其初始位置，该位置位于集合中第一个元素之前。
			virtual void Reset() = 0;

			// 获取集合中的当前元素。
			virtual const T& GetCurrent() = 0;

			// 获取集合中的当前元素。
			propertyGet(const T&, Current);
		};

	}
}


#endif