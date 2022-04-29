#ifndef UTIL_CONSOLE_H
#define UTIL_CONSOLE_H

#include <iostream>
#include <string>
#include <vector>

#define CLR_SCRN "\033[2J\033[1;1H"

namespace util {
	namespace console {
		void ignoreLine (char until = '\n');

		char getCharUnix (bool echo = true);

		template <typename T = std::string>
		T prompt (const std::vector<std::string>& messages, T defaultValue = T()) {
			T result;
			for (const std::string& message : messages) {
				std::cout << message;
				std::cin >> result;
				if (!std::cin.fail())
					return result;
				std::cin.clear();
				util::console::ignoreLine();
			}
			return defaultValue;
		}
	}
}

#endif