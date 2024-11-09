#pragma once

#include <memory>
#include <string>
#include <string_view>
#include "../str/str_rplc.hpp"

namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> unquote(std::basic_string_view<Ch, Traits> str, Ch delim = '"', Ch esc = '\\') noexcept {
		using Str = std::basic_string<Ch, Traits, Alloc>;
		str.remove_prefix(str[0] == delim);
		str.remove_suffix(str[str.size() - 1] == delim);
		const Str esc_delim = Str(1, esc) + delim;
		if (delim == esc) {
			return xieite::str_rplc(str, esc_delim, delim);
		} else {
			return xieite::str_rplc(xieite::str_rplc(str, Str(2, esc), esc), esc_delim, delim);
		}
	}
}
