#pragma once
#include <string>

namespace whermst {
	inline std::string tolower(const std::string& str){
		std::string result = str;

		//convert to lowercase
		for (char& c : result) {
			c = std::tolower(c);
		}

		return result;
	}
}
