#pragma once

#include <array>
#include <concepts>
#include <cstddef>
#include <functional>
#include <initializer_list>
#include <limits>
#include <ranges>
#include <utility>
#include "../math/bit_size.hpp"
#include "../math/sign_cast.hpp"
#include "../meta/arity.hpp"
#include "../meta/is_invoc.hpp"
#include "../meta/is_nothrow_invoc.hpp"
#include "../pp/fn.hpp"

namespace xieite {
	template<std::integral K, typename V, std::ranges::input_range R = std::initializer_list<std::pair<K, V>>, xieite::is_invoc<V(std::ranges::range_common_reference_t<R>)> F = decltype(XIEITE_FN(static_cast<V>($0)))>
	[[nodiscard]] constexpr std::array<V, (1uz << xieite::bit_size<K>)> make_sparse_array(R&& entries, F&& fn = {})
	noexcept(xieite::is_nothrow_invoc<F, V(std::ranges::range_common_reference_t<R>)>) {
		static_assert(std::numeric_limits<K>::digits <= 16, "key type must be reasonably small");
		static_assert(xieite::arity<std::ranges::range_value_t<R>> == 2, "range entries must each have one key and one value");
		auto result = std::array<V, (1uz << xieite::bit_size<K>)>();
		for (const auto& [key, value] : entries) {
			result[xieite::sign_cast<std::size_t>(static_cast<K>(std::forward_like<R>(key)))] = std::invoke(fn, std::forward_like<R>(value));
		}
		return result;
	}
}
