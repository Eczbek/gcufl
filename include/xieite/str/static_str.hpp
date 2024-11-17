#pragma once

#include <string>
#include <string_view>
#include "../str/fixed_str.hpp"

namespace xieite {
	template<xieite::fixed_str fstr, typename Traits = std::char_traits<typename decltype(fstr)::value_type>>
	inline constexpr auto static_str = std::basic_string_view<typename decltype(fstr)::value_type, Traits>(fstr.data.begin(), fstr.data.end());
}
