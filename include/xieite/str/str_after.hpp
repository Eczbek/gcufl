#pragma once

#include <string>
#include <string_view>
#include "../str/sv.hpp"

namespace xieite {
	template<typename C = char, typename Traits = std::char_traits<C>>
	[[nodiscard]] constexpr std::basic_string_view<C, Traits> str_after(std::basic_string_view<C, Traits> str, xieite::sv<C, Traits> start) noexcept {
		const std::size_t idx = str.find(start);
		return (idx == std::string::npos) ? "" : str.substr(idx + start.size());
	}
}
