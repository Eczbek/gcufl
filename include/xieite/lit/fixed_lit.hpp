#pragma once

#include "../str/fixed_str.hpp"

namespace xieite::fixed_lit {
	template<xieite::fixed_str str>
	[[nodiscard]] constexpr auto operator""_fixed() noexcept {
		return str;
	}
}
