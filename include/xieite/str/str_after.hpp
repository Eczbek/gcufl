#pragma once

#include <string>
#include <string_view>
#include "../str/sv.hpp"

namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> str_after(std::basic_string_view<Ch, Traits> str, xieite::sv<Ch, Traits> start) noexcept {
		const std::size_t idx = str.find(start);
		return (idx == std::string::npos) ? "" : str.substr(idx + start.size());
	}
}
