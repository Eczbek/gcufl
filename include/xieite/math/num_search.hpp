#pragma once

#include <concepts>
#include <functional>
#include <type_traits>
#include "../math/almost_eq.hpp"
#include "../math/neg.hpp"
#include "../meta/is_arith.hpp"
#include "../meta/is_invoc.hpp"
#include "../meta/is_nothrow_invoc.hpp"

namespace xieite {
	template<xieite::is_arith T, xieite::is_invoc<bool(T)> F>
	[[nodiscard]] constexpr T num_search(F&& cond, T min, std::type_identity_t<T> max)
	noexcept(xieite::is_nothrow_invoc<F, bool(T)>) {
		while (true) {
			const T mid = static_cast<T>((min + max) / 2);
			if (xieite::almost_eq(mid, min) || xieite::almost_eq(mid, max)) {
				return mid;
			}
			(std::invoke_r<bool>(cond, mid) ? max : min) = mid;
		}
	}

	template<xieite::is_arith T, xieite::is_invoc<bool(T)> F>
	[[nodiscard]] constexpr T num_search(F&& cond)
	noexcept(xieite::is_nothrow_invoc<F, bool(T)>) {
		if constexpr (!std::unsigned_integral<T>) {
			if (std::invoke_r<bool>(cond, static_cast<T>(0))) {
				T min = -1;
				while (std::invoke_r<bool>(cond, min)) {
					min *= 2;
				}
				return xieite::num_search(cond, min, 0);
			}
		}
		T max = 1;
		while (!std::invoke_r<bool>(cond, max)) {
			max *= 2;
		}
		return xieite::num_search(cond, static_cast<T>(0), max);
	}
}
