#pragma once

#include "../math/point2d.hpp"
#include "../math/poly2d.hpp"
#include "../math/rotate2d.hpp"
#include "../meta/is_linear2d.hpp"

namespace xieite {
	template<typename T = double, xieite::is_linear2d<T> L>
	[[nodiscard]] constexpr xieite::point2d<T> refl2d(xieite::point2d<T> point, const L& mirror) noexcept {
		return xieite::rotate2d(point, (mirror.angle() - mirror.start.angle_to(point)) * 2);
	}

	template<typename T = double, xieite::is_linear2d<T> L0, xieite::is_linear2d<T> L1>
	[[nodiscard]] constexpr L0 refl2d(const L0& line, const L1& mirror) noexcept {
		return L0(
			xieite::rotate2d(line.start, (mirror.angle() - mirror.start.angle_to(line.start)) * 2),
			xieite::rotate2d(line.end, (mirror.angle() - mirror.start.angle_to(line.end)) * 2)
		);
	}

	template<typename T = double, xieite::is_linear2d<T> L>
	[[nodiscard]] constexpr xieite::poly2d<T> refl2d(xieite::poly2d<T> poly, const L& mirror) noexcept {
		for (xieite::point2d<T>& point : poly.points) {
			point = xieite::rotate2d(point, (mirror.angle() - mirror.start.angle_to(point)) * 2);
		}
		return poly;
	}
}
