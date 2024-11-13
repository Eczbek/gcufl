#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include "../meta/end.hpp"
#include "../meta/id.hpp"
#include "../str/chv.hpp"

namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, xieite::end...,
		typename Str = std::basic_string<Ch, Traits, Alloc>,
		typename ChV = xieite::chv<Ch, Traits>>
	[[nodiscard]] constexpr Str str_rplc(Str str, xieite::id<ChV> orig, xieite::id<ChV> replc) noexcept {
		std::size_t i = 0;
		while (true) {
			i = str.find(orig, i);
			if (i == std::string::npos) {
				break;
			}
			str.replace(i, orig.size(), replc);
			++i;
		}
		return str;
	}
}
