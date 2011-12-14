#ifndef CORE_ARRAY_H
#define CORE_ARRAY_H


#include "IEnumerable.h"

namespace System {

	// 提供创建、操作、搜索和排序数组的方法。
	template<typename T>
	class Array : public Collections::IEnumerable<T> {
		T *_data;
		int _length;

	public:

		Array()
			: _length(0) {
			_data = new T[0];
		}

		Array(int length) 
		: _length(length) {
			THROW_IF1(length < 0, ArgumentsOutOfRangeException, "length", length);
			_data = new T[length];

			for ( int i = 0; i < length; i++ ){
				_data[i] = T();
			}
		}

		Array(const T* data, int length)
		: _length(length), _data(data) {

			THROW_IF(!data, ArgumentsNullException, "data");

			/*_data = new T[length];

			//  memcpy(_data, v, length);

			for ( int i = 0; i < length; i++ ){
				_data[i] = v[i];
			}*/
		}

		virtual ~Array(){
			delete[] _data;
		}

		Array& operator =(const Array& v){
			delete[] _data;

			_length = v._length;
			_data = v._data;

			return *this;
		}

		inline T& operator[] (const int index){
			THROW_IF(index < 0 || index >= _length, ArgumentsOutOfRangeException, "index");
			return _data[index];
		}

		/*inline const T& operator[] (const int idx) const{
			THROW_IF(index < 0 || index >= _length, ArgumentsOutOfRangeException, "index");
			return _data[index];
		}*/

		inline operator T*() const{
			return _data;
		}

		inline int GetLength() const {
			return _length;
		}


		class ArrayEnumerator : public Collections::IEnumerator<T> {
			const Array<T> *_owner;
			int _current;

		public:

			ArrayEnumerator(const Array<T> *array)
				: _owner(array), _current( -1)
			{
			}

			override bool MoveNext(){
				return ++_current < _owner->_length;
			}

			override void Reset(){
				_current = -1;
			}

			override const T& GetCurrent(){
				return _owner->_data[_current];
			}
		};

		// 创建 Array 的浅表副本。
		inline __gc Array<T>* Clone() const{
			return new Array<T>(*this);
		}

		// 将当前一维 Array 的所有元素复制到指定的一维 Array 中。
		void CopyTo(Array<T>& array, int index = 0) const{
			if (sourceStart >= m_len){
				return;
			}
			int pos = 0;
			for (int i = sourceStart; index < Length; x++) {
				array._data[pos++] = m_data[x];
			}
		}

		//// 使用二进制方式将当前一维 Array 的所有元素复制到指定的一维 Array 中。
		//void CopyToBinary(Array<T>& array, int index = 0) const
		//{
		//	if (index >= m_len)
		//	{
		//		return;
		//	}
		//	int len = m_len - index;
		//	if (len >= array.Length())
		//	{
		//		len = array.Length();
		//	}
		//	memcpy(array.m_data, &m_data[index], sizeof(T) * len);
		//}

		// 获取当前 Array 中指定元素的值。
		T* GetValue(int index){
			return _data + index;
		}

		virtual __gc Collections::IEnumerator<T>* GetEnumerator(){
			return new ArrayEnumerator(this);
		}

		// 将某值设置给一维 Array 中指定位置的元素。
		void SetValue(T* value, int index){
			_data[index] = *value;
		}

		// 确定指定数组包含的元素是否与指定谓词定义的条件匹配。
		bool Equals(const Array<T>& a) const{
			// TODO
			/*if (m_len != a.m_len)
			{
				return false;
			}
			for (int x = 0; x < m_len; x++)
			{
				if (m_data[x] != a.m_data[x])
				{
					return false;
				}
			}*/
			return true;
		}

		// 确定指定数组包含的元素是否与指定谓词定义的条件匹配。
		static bool Equals(const Array<T>& array1, int index1, const Array<T>& array2, int index2, int length) {
			/// TODO
			/*int length2 = array2._length - index2;
			int diff = (array1._length - index1) != (array2._length - index2);
			if (array1._length)
			{			
			return false;
			}

			int length = a.Length() - astart;
			if (length < len)
			{
			return false;
			}
			for ( int x = 0; x < length; x++)
			{
			if (!(a[x + astart] == b[x + bstart]))
			{
			return false;
			}
			}*/
			return true;
		}

		// 确定指定数组包含的元素是否与指定谓词定义的条件匹配。
		inline static bool Equals(const Array<T>& a, const Array<T>& b) {
			return Equals(a, 0, b, 0, a._length);
		}

		// 使用二分算法在一维的排序 Array 中搜索值。
		static int BinarySearch(Array<T> array, int index, int length, const T& value){
			// TODO
			return -1;
		}

		// 从指定的源索引开始，复制 Array 中的一系列元素，将它们粘贴到另一 Array 中（从指定的目标索引开始）。长度和索引指定为 64 位整数。
		static void Copy(const Array<T>& sourceArray, int sourceIndex, Array<T>& destinationArray, int destinationIndex, int length)
		{
			while ( length-- ){
				destinationArray[destinationIndex++] = sourceArray[sourceIndex++];
			}
		}

		// 将 Array 中的一系列元素设置为零、false 或 NULL 指针，具体取决于元素类型。
		static void Clear(Array<T> array, int index, int length){
			THROW_IF_LENGTH(index, length, _length);
			for ( int right = index + length; index < right; index++ ) {
				array[index] = T();
			}
		}

		/*inline static void CopyBinary(const Array<T>& from, int fromStart, Array<T>& to, int toStart, int length)
		{
			memmove(&to.m_data[toStart], &from.m_data[fromStart], sizeof(T) * length);
		}*/

	};

}

#endif
