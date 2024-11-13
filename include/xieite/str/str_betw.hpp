#pragma once

#include <string>
#include <string_view>
#include "../meta/end.hpp"
#include "../meta/id.hpp"
#include "../str/chv.hpp"
#include "../str/str_after.hpp"
#include "../str/str_before.hpp"

namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>,
		xieite::end...,
		typename StrV = std::basic_string_view<Ch, Traits>,
		typename ChV = xieite::chv<Ch, Traits>>
	[[nodiscard]] constexpr StrV str_betw(StrV str, xieite::id<ChV> start, xieite::id<ChV> end) noexcept {
		return xieite::str_before(xieite::str_after(str, start), end);
	}
}
