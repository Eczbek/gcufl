#pragma once

#include "../str/fixed_str.hpp"

namespace xieite::fixed_str_lit {
	template<xieite::fixed_str fstr>
	[[nodiscard]] constexpr auto operator""_fstr() noexcept {
		return fstr;
	}
}
