


#include "CString.h"


namespace System {

	int CString::GetLength( tstring value ){
		THROW_IF(value == NULL, ArgumentsNullException, "value");
		return strlen(value);
	}

	int CString::Compare( tstring value1, tstring value2 ){
		THROW_IF(value1 == NULL, ArgumentsNullException, "value1");
		THROW_IF(value2 == NULL, ArgumentsNullException, "value2");
		return strcmp(value1, value2);
	}

	int CString::CompareIgnoreCase( tstring value1, tstring value2 ){
		THROW_IF(value1 == NULL, ArgumentsNullException, "value1");
		THROW_IF(value2 == NULL, ArgumentsNullException, "value2");
		return strcmpi(value1, value2);
	}


}