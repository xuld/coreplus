#ifndef CORE_ARRAY_H
#define CORE_ARRAY_H


#include "IEnumerable.h"

namespace System {

	// �ṩ��������������������������ķ�����
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

		// ���� Array ��ǳ������
		inline __gc Array<T>* Clone() const{
			return new Array<T>(*this);
		}

		// ����ǰһά Array ������Ԫ�ظ��Ƶ�ָ����һά Array �С�
		void CopyTo(Array<T>& array, int index = 0) const{
			if (sourceStart >= m_len){
				return;
			}
			int pos = 0;
			for (int i = sourceStart; index < Length; x++) {
				array._data[pos++] = m_data[x];
			}
		}

		//// ʹ�ö����Ʒ�ʽ����ǰһά Array ������Ԫ�ظ��Ƶ�ָ����һά Array �С�
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

		// ��ȡ��ǰ Array ��ָ��Ԫ�ص�ֵ��
		T* GetValue(int index){
			return _data + index;
		}

		virtual __gc Collections::IEnumerator<T>* GetEnumerator(){
			return new ArrayEnumerator(this);
		}

		// ��ĳֵ���ø�һά Array ��ָ��λ�õ�Ԫ�ء�
		void SetValue(T* value, int index){
			_data[index] = *value;
		}

		// ȷ��ָ�����������Ԫ���Ƿ���ָ��ν�ʶ��������ƥ�䡣
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

		// ȷ��ָ�����������Ԫ���Ƿ���ָ��ν�ʶ��������ƥ�䡣
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

		// ȷ��ָ�����������Ԫ���Ƿ���ָ��ν�ʶ��������ƥ�䡣
		inline static bool Equals(const Array<T>& a, const Array<T>& b) {
			return Equals(a, 0, b, 0, a._length);
		}

		// ʹ�ö����㷨��һά������ Array ������ֵ��
		static int BinarySearch(Array<T> array, int index, int length, const T& value){
			// TODO
			return -1;
		}

		// ��ָ����Դ������ʼ������ Array �е�һϵ��Ԫ�أ�������ճ������һ Array �У���ָ����Ŀ��������ʼ�������Ⱥ�����ָ��Ϊ 64 λ������
		static void Copy(const Array<T>& sourceArray, int sourceIndex, Array<T>& destinationArray, int destinationIndex, int length)
		{
			while ( length-- ){
				destinationArray[destinationIndex++] = sourceArray[sourceIndex++];
			}
		}

		// �� Array �е�һϵ��Ԫ������Ϊ�㡢false �� NULL ָ�룬����ȡ����Ԫ�����͡�
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
