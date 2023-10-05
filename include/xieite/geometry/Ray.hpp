#ifndef XIEITE_HEADER__GEOMETRY__RAY
#	define XIEITE_HEADER__GEOMETRY__RAY

#	include <cmath>
#	include "../geometry/Line.hpp"
#	include "../geometry/Point.hpp"
#	include "../math/almostEqualSlope.hpp"

namespace xieite::geometry {
	struct Ray {
		xieite::geometry::Point start;
		xieite::geometry::Point end;

		constexpr Ray(const xieite::geometry::Point start, const xieite::geometry::Point end) noexcept
		: start(start), end(end) {}

		constexpr Ray(const xieite::geometry::Point start, const double angle) noexcept
		: start(start), end(std::cos(angle), std::sin(angle)) {}

		friend constexpr bool operator==(const xieite::geometry::Ray& ray1, const xieite::geometry::Ray& ray2) noexcept {
			return (ray1.start == ray2.start) && xieite::math::almostEqualSlope(ray1.slope(), ray2.slope());
		}

		constexpr double angle() const noexcept {
			return this->start.angleTo(this->end);
		}

		constexpr bool containsPoint(const xieite::geometry::Point point) const noexcept {
			return xieite::math::almostEqual((this->end.x - this->start.x) * (point.y - this->start.y), (this->end.y - this->start.y) * (point.x - this->start.x)) && ((this->start.x <= this->end.x) ? (this->start.x <= point.x) : (this->start.x > point.x)) && ((this->start.y <= this->end.y) ? (this->start.y <= point.y) : (this->start.y > point.y));
		}

		constexpr double length() const noexcept {
			return std::numeric_limits<double>::infinity();
		}

		constexpr double slope() const noexcept {
			return this->start.slopeTo(this->end);
		}
	};
}

#endif
