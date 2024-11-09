#pragma once

#include <array>
#include <cstddef>
#include <memory>
#include <numeric>
#include <string>
#include "../math/bit_size.hpp"
#include "../math/sign_cast.hpp"
#include "../meta/is_ch.hpp"
#include "../str/chars.hpp"

namespace xieite {
	template<xieite::is_ch Ch = char>
	[[nodiscard]] constexpr Ch lower(Ch c) noexcept {
		using Lookup = std::array<Ch, (1uz << xieite::bit_size<Ch>)>;
		static constexpr Lookup lookup = ([] -> Lookup {
			Lookup lookup;
			std::ranges::iota(lookup, '\0');
			for (std::size_t i = 0; i < xieite::chars::alphabet_size; ++i) {
				lookup[xieite::sign_cast<std::size_t>(xieite::chars::upper[i])] = static_cast<Ch>(xieite::chars::lower[i]);
			}
			return lookup;
		})();
		return lookup[xieite::sign_cast<std::size_t>(c)];
	}

	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> lower(std::basic_string<Ch, Traits, Alloc> str) noexcept {
		for (Ch& c : str) {
			c = xieite::lower(c);
		}
		return str;
	}
}
