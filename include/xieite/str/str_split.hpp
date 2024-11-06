#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <string_view>
#include <vector>
#include "../str/sv.hpp"

namespace xieite {
	template<typename C = char, typename Traits = std::char_traits<C>, typename Alloc = std::allocator<std::basic_string_view<C, Traits>>>
	[[nodiscard]] constexpr std::vector<std::basic_string_view<C, Traits>, Alloc> str_split(std::basic_string_view<C, Traits> str, xieite::sv<C, Traits> delim, bool discard_empty = false) noexcept {
		std::vector<std::basic_string_view<C, Traits>, Alloc> result;
		std::size_t i = 0;
		while (true) {
			const std::size_t j = str.find(delim, i);
			if (j == std::string::npos) {
				break;
			}
			if (!discard_empty || (j - i)) {
				result.push_back(str.substr(i, j - i));
			}
			i = j + delim.size();
		}
		if (!discard_empty || (str.size() - i)) {
			result.push_back(str.substr(i));
		}
		return result;
	}
}
