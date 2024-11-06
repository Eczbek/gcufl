#pragma once

#include <array>
#include <concepts>
#include <cstddef>
#include <cstdint>
#include <utility>
#include "../ctnr/make_array.hpp"
#include "../fn/unroll.hpp"
#include "../math/bit_join.hpp"
#include "../math/bit_size.hpp"
#include "../math/bit_unjoin.hpp"
#include "../meta/least_uint.hpp"

namespace xieite {
	template<std::size_t channels>
	struct color {
		std::array<std::uint8_t, channels> data;

		template<std::convertible_to<std::uint8_t>... Args>
		requires(sizeof...(Args) == channels)
		explicit constexpr color(Args... args) noexcept
		: data { static_cast<std::uint8_t>(args)... } {}

		explicit constexpr color(xieite::least_uint<xieite::bit_size<std::uint8_t> * channels> value = 0) noexcept
		: data(xieite::make_array<std::uint8_t, channels>(std::views::reverse(xieite::bit_unjoin<std::uint8_t, channels>(xieite::bit_join(value))))) {}

		[[nodiscard]] friend bool operator==(const xieite::color<channels>&, const xieite::color<channels>&) = default;

		template<typename Self>
		[[nodiscard]] constexpr auto&& operator[](this Self&& self, std::size_t idx) noexcept {
			return std::forward_like<Self>(self.data[idx]);
		}

		[[nodiscard]] constexpr xieite::least_uint<xieite::bit_size<std::uint8_t> * channels> value() const noexcept {
			return xieite::unroll<channels>([this]<std::size_t... i> {
				return static_cast<xieite::least_uint<xieite::bit_size<std::uint8_t> * channels>>(xieite::bit_join(this->data[i]...).to_ullong());
			});
		}
	};
}
