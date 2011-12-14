

#include "Number.h"


namespace System {

	int Number::ToHex( char c ) {
		if (c >= '0' && c <= '9') {
			return c - '0';
		}
		if (c >= 'A' && c <= 'F') {
			return c + 10 - 'A';
		}
		if (c >= 'a' && c <= 'f') {
			return c + 10 - 'a';
		}
		return -1;
	}

}