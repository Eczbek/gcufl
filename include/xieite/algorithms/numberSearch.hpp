#pragma once

#include <xieite/concepts/Arithmetic.hpp>
#include <xieite/concepts/CallbackSelector.hpp>
#include <xieite/math/approximatelyEqual.hpp>

namespace xieite::algorithms {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]]
	constexpr Number numberSearch(const xieite::concepts::CallbackSelector<Number> auto& selector, Number minimum, Number maximum) {
		while (true) {
			const Number middle = (minimum + maximum) / 2;
			if (xieite::math::approximatelyEqual(middle, minimum) || xieite::math::approximatelyEqual(middle, maximum)) {
				return middle;
			}
			(selector(middle) ? maximum : minimum) = middle;
		}
	}

	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]]
	constexpr Number numberSearch(const xieite::concepts::CallbackSelector<Number> auto& selector) {
		Number minimum = -1;
		Number maximum = 1;
		if (selector(0)) {
			maximum = 0;
			while (selector(minimum)) {
				minimum -= absolute(minimum);
			}
		} else {
			minimum = 0;
			while (!selector(maximum)) {
				maximum += absolute(maximum);
			}
		}
		return numberSearch(selector, minimum, maximum);
	}
}
