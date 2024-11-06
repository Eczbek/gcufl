#pragma once

#include <string>
#include <string_view>
#include "../str/sv.hpp"

namespace xieite {
	template<typename C = char, typename Traits = std::char_traits<C>>
	[[nodiscard]] constexpr std::basic_string_view<C, Traits> str_before(std::basic_string_view<C, Traits> str, xieite::sv<C, Traits> end) noexcept {
		return str.substr(0, str.rfind(end));
	}
}
