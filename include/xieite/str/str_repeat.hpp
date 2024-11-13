#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include "../meta/end.hpp"
#include "../str/chv.hpp"

namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, xieite::end...,
		typename Str = std::basic_string<Ch, Traits, Alloc>>
	[[nodiscard]] constexpr Str str_repeat(std::size_t n, xieite::chv<Ch, Traits> str) noexcept {
		Str result;
		result.reserve(str.size() * n);
		while (n--) {
			result += str;
		}
		return result;
	}
}
