#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>
#include "../fn/repeat.hpp"
#include "../pp/fwd.hpp"

namespace xieite {
	constexpr void make_constexpr(auto&& fn, std::uint8_t value) {
		xieite::repeat<(1uz << std::numeric_limits<std::uint8_t>::digits)>([&fn, value]<std::size_t i> -> void {
			static constexpr std::uint8_t j = static_cast<std::uint8_t>(i);
			if (value == j) {
				XIEITE_FWD(fn).template operator()<j>();
			}
		});
	}
}
