#pragma once

#include <array>
#include <cstddef>
#include <functional>
#include <utility>
#include "../fn/unroll.hpp"
#include "../meta/is_rm_cvref_same_as.hpp"
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"

namespace xieite {
	template<typename F, typename V, std::size_t size, xieite::is_rm_cvref_same_as<std::array<V, size>> Array>
	constexpr auto apply_array(F&& fn, Array&& array)
	XIEITE_ARROW(xieite::unroll<size>(
		[&fn, &array]<std::size_t... i>
		XIEITE_ARROW(std::invoke(XIEITE_FWD(fn), std::forward_like<Array>(array[i])...))
	))

	template<typename T, typename V, std::size_t size, xieite::is_rm_cvref_same_as<std::array<V, size>> Array>
	[[nodiscard]] constexpr auto apply_array(Array&& array)
	XIEITE_ARROW(xieite::unroll<size>(
		[&array]<std::size_t... i>
		XIEITE_ARROW(T(std::forward_like<Array>(array[i])...))
	))
}
