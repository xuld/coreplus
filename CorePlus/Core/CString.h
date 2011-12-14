#ifndef CORE_Ctstring_H
#define CORE_Ctstring_H

#include <string.h>
#include <tchar.h>

#include "Type.h"
#include "Array.h"


namespace System {

	typedef TCHAR tchar;
	typedef const TCHAR* tstring;

	singleton class API CString {
	public:

		// ����һ���ַ��������䳤�ȡ� 
		static inline int GetLength(tstring value);

		// �Ƚ��ַ�����
		static inline int Compare(tstring value1, tstring value2);

		// ���Դ�Сд���Ƚ��ַ�����
		static inline int CompareIgnoreCase(tstring value1, tstring value2);

		static inline int IndexOf(tstring value, tchar ch, int count);

		static inline int IndexOf(tstring value, tchar ch);

		static inline int IndexOf(tstring value, tstring substring, int count);

		static inline int IndexOf(tstring value, tstring substring);

		static inline int IndexOfIgnoreCase(tstring value, tchar ch, int count);

		static inline int IndexOfIgnoreCase(tstring value, tchar ch);

		static inline int IndexOfIgnoreCase(tstring value, tstring substring, int count);

		static inline int IndexOfIgnoreCase(tstring value, tstring substring);

		static inline int Copy(tstring value1, tstring value2, int count);

		static inline __gc tstring Concat(tstring value1, tstring value2);

		static inline int LastIndexOf(tstring value, tchar ch, int count);

		static inline int LastIndexOf(tstring value, tchar ch);

		static inline int LastIndexOf(tstring value, tstring substring, int count);

		static inline int LastIndexOf(tstring value, tstring substring);

		static inline int LastIndexOfIgnoreCase(tstring value, tchar ch, int count);

		static inline int LastIndexOfIgnoreCase(tstring value, tchar ch);

		static inline int LastIndexOfIgnoreCase(tstring value, tstring substring, int count);

		static inline int IndexNotOf(tstring value, tchar ch, int count);

		static inline int IndexNotOf(tstring value, tchar ch);

		static inline int IndexNotOf(tstring value, tstring substring, int count);

		static inline int IndexNotOf(tstring value, tstring substring);

		static inline int IndexNotOfIgnoreCase(tstring value, tchar ch, int count);

		static inline int IndexNotOfIgnoreCase(tstring value, tchar ch);

		static inline int IndexNotOfIgnoreCase(tstring value, tstring substring, int count);

		static inline void Reverse(tstring value, int start, int length);

		// ����Ϊ��չʵ�֡�

		static inline int Count(tstring value1, tstring value2);

		static inline int Count(tstring value1, tchar value2);

		static inline __gc tstring Create(tchar c, int count);

		static inline __gc tstring Create(int length);

		static inline int DistanceCompare(tstring value1, tstring value2);

		static inline int EndsWith(tstring value1, tstring value2);

		static inline int EndsWith(tstring value1, tchar value2);

		static inline int EndsWithIgnoreCase(tstring value1, tstring value2);

		static inline int EndsWithIgnoreCase(tstring value1, tchar value2);

		static inline __gc tstring Format(tstring value, ...);

		// ���ַ���ָ������λ�ò���һ��ָ�����ַ�������  
		static inline __gc tstring Insert (tstring value1, tstring value2);

		//// ���ַ���ָ������λ�ò���һ��ָ�����ַ�������  
		//static inline __gc tstring Join (const IEnumerable<void*>& value);

		//// ���ַ���ָ������λ�ò���һ��ָ�����ַ�������  
		//static inline __gc tstring Join (const IEnumerable<void*>& value);

		// ���� 2 ���ַ�������������ַ����� 
		static inline int MaxSubString(tstring value1, tstring value2);

		// �Ҷ����ʵ���е��ַ����������ָ���� Unicode �ַ�����Դﵽָ�����ܳ��ȡ�   
		static inline __gc tstring PadLeft (tstring value, int count);

		// �Ҷ����ʵ���е��ַ����������ָ���� Unicode �ַ�����Դﵽָ�����ܳ��ȡ�   
		static inline __gc tstring PadRight (tstring value, int count);

		// ɾ���ַ�����ָ�������ַ�����  
		static inline __gc tstring Remove(tstring value1, tstring value2);

		// ɾ���ַ�����ָ�������ַ�����  
		static inline __gc tstring RemoveIgnoreCase(tstring value1, tstring value2);

		// ���ַ�������ƥ�����滻Ϊ����ָ�����ַ����� 
		static inline __gc tstring Replace(tstring value, tstring form,  tstring to );

		// ���ַ�������ƥ�����滻Ϊ����ָ�����ַ����� 
		static inline __gc tstring ReplaceIgnoreCase(tstring value, tstring form,  tstring to);

		// ���ַ�������ƥ�����滻Ϊ����ָ�����ַ����� 
		static inline __gc tstring Replace(tstring value, tchar form,  tchar to);

		// ���ַ�������ƥ�����滻Ϊ����ָ�����ַ����� 
		static inline __gc tstring ReplaceIgnoreCase(tstring value, tchar form,  tchar to);

		static inline __gc Array<tstring>* Split(tstring value, tstring s);

		static inline __gc Array<tstring>* Split(tstring value, tchar s);

		static inline __gc Array<tstring>* Split(tstring value, const Array<tchar>& s);

		static inline __gc tstring SubString(tstring value, int count);

		static inline __gc tstring ToLower(tstring value);

		static inline __gc tstring ToUpper(tstring value);

		static inline __gc tstring Trim(tstring value);

		static inline __gc tstring TrimEnd(tstring value);

		static inline __gc tstring TrimStart(tstring value);
	};
}



/*

Enquote  ����һ��ָ�������ַ����� 

Escape   ���ַ���ת��Ϊ Unicode �ַ�����


GetPinYin  ����תƴ����д �� 

GetPY  ȡ�����ַ���ƴ����ĸ ��

HtmlAttributeEncode ���ַ�����С�޶ȵ�ת��Ϊ HTML ������ַ�����  
HtmlDecode ���Ѿ�Ϊ HTTP ������й� HTML ������ַ���ת��Ϊ�ѽ�����ַ�����  
HtmlEncode ���ַ���ת��Ϊ HTML ������ַ�����  
HtmlNoScript ���������ַ���  
HtmlNoTags ��� Html �ı�ǩ��  
HtmlToString HTML����ת����TXT��ʽ��  
HtmlTrim ȥ����βp��br��  
Hyphenate   ���ַ���תΪ Hyphenate ���� 
Indent ����һ���ַ����� 

InnerString(String, Int32)   ɾ���ַ�����β1���ȵ��ַ����� 

IsMatch ָʾ������ʽʹ�� pattern ������ָ����������ʽ�� options �������ṩ��ƥ��ѡ���Ƿ��������ַ������ҵ�ƥ���  

JSDecode js���롣  
JSEncode js����  


Left


Plain ɾ�����лس���  


RemoveAfter �����ء�  
RemoveBefore �����ء�  
RemoveEmptys ɾ���ַ����Ŀհס� ���� ' '��'\t'��'\r'��'\n'�ȶ����Ƴ���  
RemoveEnd �����ء�  


RemoveStart �����ء�  
RemoveUnvisible ɾ�����ɼ��ַ���  


Right  



SplitAndTrim �����ء�  
SplitNewLine �������ַ����ָ  
SplitNewLineAndTrim �������ַ����ָɾ���ո�  
StartsWith ȷ�����ַ����Ŀ�ͷ�Ƿ���ָ�����ַ���ƥ�䡣  
StartsWithIgnoreCase �����ء�  
StringToHtml ��TXT��ʽת����HTML���롣  
Substr ��ȡһ�����ַ�����  



Surround ��һ���ַ�����һ�����ϰ�Χ�����ԭ���Ѱ�Χ���򲻽��в�����  
ToCamel �����ء�  
ToCLength ���ַ���תΪһ�����ȡ�������2�����ȡ�  
ToDbc ת��ǵĺ���(DBC case) ��  
ToHexString ��һ���ֽ�����תΪʮ�������ַ�����  
ToLength �����ء�  



ToPascal �����ء�  
ToSbc תȫ�ǵĺ���(SBC case)��  
ToTimeString �����ء�  


Trigger ���ַ�����a��b�л���  
TriggerIgnoreCase ���ַ�����a��b�л��� �������еĴ�Сд��  



TrimToLength �����ء�  
UBBToHTML UBB�ַ�ת����HTML�ַ���  
UnCapitalize ���ַ�������ĸСд��  
Unescape ���Ѿ�Ϊ�� URL �д����������ַ���ת��Ϊ������ַ�����  
UnicodeDecode �����ء�  
UnicodeEncode �����ء�  
Unsurround �����ء�  
UrlDecode �����ء�  
UrlEncode �� URL �ַ�����·�����ֽ��б��룬�Խ��д� Web ���������ͻ��˵Ŀɿ��� HTTP ���䡣  
UrlEncodeComponent �����ء�  







*/


#endif