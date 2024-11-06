#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include "../str/sv.hpp"

namespace xieite {
	template<typename C = char, typename Traits = std::char_traits<C>, typename Alloc = std::allocator<C>>
	[[nodiscard]] constexpr std::basic_string<C, Traits, Alloc> trunc(std::basic_string<C, Traits, Alloc> str, std::size_t size, xieite::sv<C, Traits> sfx = "") noexcept {
		using Str = std::basic_string<C, Traits, Alloc>;
		return (str.size() <= size)
			? str
			: ((sfx.size() > size)
				? Str(sfx.substr(0, size))
				: (str.substr(0, size - sfx.size()) + sfx));
	}
}
