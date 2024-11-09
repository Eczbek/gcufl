#pragma once

#include <cstddef>
#include <cstdint>
#include <type_traits>
#include "../math/bit_size.hpp"

namespace xieite {
	template<std::size_t bits>
	using least_uint = std::conditional_t<
		(bits <= xieite::bit_size<std::uint_least8_t>),
		std::uint_least8_t,
		std::conditional_t<
			(bits <= xieite::bit_size<std::uint_least16_t>),
			std::uint_least16_t,
			std::conditional_t<
				(bits <= xieite::bit_size<std::uint_least32_t>),
				std::uint_least32_t,
				std::uint_least64_t
			>
		>
	>;
}
