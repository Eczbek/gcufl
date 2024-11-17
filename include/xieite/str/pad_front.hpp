#pragma once

#include <cstddef>
#include <memory>
#include <string>

namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> pad_front(std::basic_string_view<Ch, Traits> strv, std::size_t size, Ch c = ' ') noexcept {
		using Str = std::basic_string<Ch, Traits, Alloc>;
		return (strv.size() < size)
			? ((size - strv.size(), c) + Str(strv))
			: Str(strv);
	}
}
