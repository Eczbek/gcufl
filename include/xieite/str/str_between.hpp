#pragma once

#include <string>
#include <string_view>
#include "../str/str_after.hpp"
#include "../str/str_before.hpp"
#include "../str/sv.hpp"

namespace xieite {
	template<typename C = char, typename Traits = std::char_traits<C>>
	[[nodiscard]] constexpr std::basic_string_view<C, Traits> str_between(std::basic_string_view<C, Traits> str, std::type_identity_t<xieite::sv<C, Traits>> start, std::type_identity_t<xieite::sv<C, Traits>> end) noexcept {
		return xieite::str_before(xieite::str_after(str, start), end);
	}
}
