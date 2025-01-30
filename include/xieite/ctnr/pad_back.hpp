#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <string_view>
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"
#include "../trait/is_ch.hpp"

namespace xieite {
	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> pad_back(const std::basic_string<Ch, Traits, Alloc>& str, std::size_t size, Ch c = ' ', Alloc&& alloc = {}) noexcept(false) {
		return (str.size() < size)
			? (str + std::basic_string<Ch, Traits, Alloc>(size - str.size(), c, XIEITE_FWD(alloc)))
			: str;
	}

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto pad_back(std::basic_string_view<Ch, Traits> strv, std::size_t size, Ch c = ' ', Alloc&& alloc = {})
		XIEITE_ARROW(xieite::pad_back(std::basic_string<Ch, Traits, Alloc>(strv, alloc), size, c, alloc))

	template<xieite::is_ch Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto pad_back(const Ch(& str)[n], std::size_t size, Ch c = ' ', Alloc&& alloc = {})
		XIEITE_ARROW(xieite::pad_back(std::basic_string<Ch, Traits, Alloc>(str, n, alloc), size, c, alloc))
}

