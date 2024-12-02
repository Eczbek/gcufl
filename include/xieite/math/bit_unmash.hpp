#pragma once

#include <array>
#include <bitset>
#include <concepts>
#include <cstddef>
#include <tuple>
#include <utility>
#include "../fn/repeat.hpp"
#include "../math/bit_size.hpp"
#include "../math/least_uint.hpp"
#include "../meta/try_unsign.hpp"

namespace xieite {
	template<std::size_t... sizes, std::size_t bits>
	requires(bits >= (... + sizes))
	[[nodiscard]] constexpr std::tuple<xieite::least_uint<sizes>...> bit_unmash(std::bitset<bits> value) noexcept {
		std::tuple<xieite::least_uint<sizes>...> result;
		xieite::repeat<sizeof...(sizes)>([&value, &result]<std::size_t i> -> void {
			using T = xieite::least_uint<sizes...[i]>;
			std::get<i>(result) = static_cast<T>(std::exchange(value, value >> sizes...[i]).to_ullong()) & (static_cast<T>(-1) >> (xieite::bit_size<T> - sizes...[i]));
		});
		return result;
	}

	template<std::integral T, std::size_t... sizes, std::size_t bits>
	requires(bits >= (... + sizes))
	[[nodiscard]] constexpr std::array<T, sizeof...(sizes)> bit_unmash(std::bitset<bits> value) noexcept {
		return std::array<T, sizeof...(sizes)> {
			([&value] -> T {
				const T item = static_cast<T>(value.to_ullong()) & (static_cast<xieite::try_unsign<T>>(-1) >> (xieite::bit_size<T> - sizes));
				value >>= sizes;
				return item;
			})()...
		};
	}
}
