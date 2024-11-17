#pragma once

#include <cstddef>
#include <cstdint>
#include "../fn/repeat.hpp"
#include "../math/bit_size.hpp"
#include "../pp/fwd.hpp"

namespace xieite {
	constexpr void make_constexpr(auto&& fn, std::uint8_t value) {
		xieite::repeat<(1uz << xieite::bit_size<std::uint8_t>)>([&fn, value]<std::size_t i> -> void {
			static constexpr std::uint8_t j = static_cast<std::uint8_t>(i);
			if (value == j) {
				XIEITE_FWD(fn).template operator()<j>();
			}
		});
	}
}
