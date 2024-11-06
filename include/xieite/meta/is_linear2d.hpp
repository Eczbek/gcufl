#pragma once

#include <type_traits>
#include "../meta/is_arith.hpp"
#include "../meta/is_same_as_any.hpp"

namespace xieite {
	template<xieite::is_arith>
	struct line2d;

	template<xieite::is_arith>
	struct ray2d;

	template<xieite::is_arith>
	struct segm2d;

	template<typename T, typename U = double>
	concept is_linear2d =
		xieite::is_same_as_any<
			std::remove_cv_t<T>,
			xieite::line2d<U>,
			xieite::ray2d<U>,
			xieite::segm2d<U>
		>;
}
