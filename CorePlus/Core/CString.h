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

		// 根据一个字符串返回其长度。 
		static inline int GetLength(tstring value);

		// 比较字符串。
		static inline int Compare(tstring value1, tstring value2);

		// 忽略大小写，比较字符串。
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

		// 以下为扩展实现。

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

		// 在字符串指定索引位置插入一个指定的字符串对象。  
		static inline __gc tstring Insert (tstring value1, tstring value2);

		//// 在字符串指定索引位置插入一个指定的字符串对象。  
		//static inline __gc tstring Join (const IEnumerable<void*>& value);

		//// 在字符串指定索引位置插入一个指定的字符串对象。  
		//static inline __gc tstring Join (const IEnumerable<void*>& value);

		// 计算 2 个字符串的最长公共子字符串。 
		static inline int MaxSubString(tstring value1, tstring value2);

		// 右对齐此实例中的字符，在左边用指定的 Unicode 字符填充以达到指定的总长度。   
		static inline __gc tstring PadLeft (tstring value, int count);

		// 右对齐此实例中的字符，在左边用指定的 Unicode 字符填充以达到指定的总长度。   
		static inline __gc tstring PadRight (tstring value, int count);

		// 删除字符串中指定的子字符串。  
		static inline __gc tstring Remove(tstring value1, tstring value2);

		// 删除字符串中指定的子字符串。  
		static inline __gc tstring RemoveIgnoreCase(tstring value1, tstring value2);

		// 将字符串所有匹配项替换为其他指定的字符串。 
		static inline __gc tstring Replace(tstring value, tstring form,  tstring to );

		// 将字符串所有匹配项替换为其他指定的字符串。 
		static inline __gc tstring ReplaceIgnoreCase(tstring value, tstring form,  tstring to);

		// 将字符串所有匹配项替换为其他指定的字符串。 
		static inline __gc tstring Replace(tstring value, tchar form,  tchar to);

		// 将字符串所有匹配项替换为其他指定的字符串。 
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

Enquote  生成一个指定引号字符串。 

Escape   将字符串转换为 Unicode 字符串。


GetPinYin  汉字转拼音缩写 。 

GetPY  取单个字符的拼音声母 。

HtmlAttributeEncode 将字符串最小限度地转换为 HTML 编码的字符串。  
HtmlDecode 将已经为 HTTP 传输进行过 HTML 编码的字符串转换为已解码的字符串。  
HtmlEncode 将字符串转换为 HTML 编码的字符串。  
HtmlNoScript 过滤特殊字符。  
HtmlNoTags 清除 Html 的标签。  
HtmlToString HTML代码转换成TXT格式。  
HtmlTrim 去掉首尾p与br。  
Hyphenate   将字符串转为 Hyphenate 规则。 
Indent 缩进一个字符串。 

InnerString(String, Int32)   删除字符串首尾1长度的字符串。 

IsMatch 指示正则表达式使用 pattern 参数中指定的正则表达式和 options 参数中提供的匹配选项是否在输入字符串中找到匹配项。  

JSDecode js解码。  
JSEncode js编码  


Left


Plain 删除所有回车。  


RemoveAfter 已重载。  
RemoveBefore 已重载。  
RemoveEmptys 删除字符串的空白。 包括 ' '、'\t'、'\r'、'\n'等都被移除。  
RemoveEnd 已重载。  


RemoveStart 已重载。  
RemoveUnvisible 删除不可见字符。  


Right  



SplitAndTrim 已重载。  
SplitNewLine 将多行字符串分割。  
SplitNewLineAndTrim 将多行字符串分割并删除空格。  
StartsWith 确定此字符串的开头是否与指定的字符串匹配。  
StartsWithIgnoreCase 已重载。  
StringToHtml 把TXT格式转换成HTML代码。  
Substr 获取一个子字符串。  



Surround 让一个字符串被一个符合包围，如果原先已包围，则不进行操作。  
ToCamel 已重载。  
ToCLength 将字符串转为一定长度。中文算2个长度。  
ToDbc 转半角的函数(DBC case) 。  
ToHexString 将一个字节数组转为十六进制字符串。  
ToLength 已重载。  



ToPascal 已重载。  
ToSbc 转全角的函数(SBC case)。  
ToTimeString 已重载。  


Trigger 将字符串在a，b切换。  
TriggerIgnoreCase 将字符串在a，b切换。 忽略所有的大小写。  



TrimToLength 已重载。  
UBBToHTML UBB字符转换成HTML字符。  
UnCapitalize 将字符串首字母小写。  
Unescape 将已经为在 URL 中传输而编码的字符串转换为解码的字符串。  
UnicodeDecode 已重载。  
UnicodeEncode 已重载。  
Unsurround 已重载。  
UrlDecode 已重载。  
UrlEncode 对 URL 字符串的路径部分进行编码，以进行从 Web 服务器到客户端的可靠的 HTTP 传输。  
UrlEncodeComponent 已重载。  







*/


#endif