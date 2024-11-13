#pragma once

#include <concepts>
#include <functional>
#include <type_traits>
#include "../pp/fn.hpp"
#include "../pp/fwd.hpp"
#include "../trait/is_cp_ctor.hpp"
#include "../trait/is_nothrow_cp_ctor.hpp"
#include "../trait/is_nothrow_invoc.hpp"

namespace xieite {
	template<xieite::is_cp_ctor T, std::invocable<T&&> F>
	[[nodiscard]] constexpr T also(T&& value, F&& fn = {})
	noexcept(xieite::is_nothrow_cp_ctor<T> && xieite::is_nothrow_invoc<F, void(T&&)>) {
		const T copy = value;
		std::invoke(XIEITE_FWD(fn), value);
		return copy;
	}

	template<xieite::is_cp_ctor T, std::invocable<> F>
	[[nodiscard]] constexpr T also(T&& value, F&& fn = {})
	noexcept(xieite::is_nothrow_cp_ctor<T> && xieite::is_nothrow_invoc<F>) {
		return xieite::also(XIEITE_FWD(value), XIEITE_FN_LOCAL(std::invoke(XIEITE_FWD(fn))));
	}
}
