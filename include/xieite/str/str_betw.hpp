#pragma once

#include <string>
#include <string_view>
#include "../str/str_after.hpp"
#include "../str/str_before.hpp"
#include "../str/sv.hpp"

namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> str_betw(std::basic_string_view<Ch, Traits> str, std::type_identity_t<xieite::sv<Ch, Traits>> start, std::type_identity_t<xieite::sv<Ch, Traits>> end) noexcept {
		return xieite::str_before(xieite::str_after(str, start), end);
	}
}
