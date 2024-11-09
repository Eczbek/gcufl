#pragma once

#include <cstddef>
#include <string>
#include <string_view>
#include "../str/sv.hpp"

namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> trim_back(std::basic_string_view<Ch, Traits> str, xieite::sv<Ch, Traits> chars) noexcept {
		const std::size_t end = str.find_last_not_of(chars);
		return (end == std::string::npos) ? "" : str.substr(0, end + 1);
	}
}
