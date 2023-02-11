#pragma once
#include <xieite/geometry/LineLike.hpp>
#include <xieite/geometry/Point.hpp>

namespace xieite::geometry {
	struct Segment
	: xieite::geometry::LineLike {
		constexpr Segment(const xieite::geometry::Point start, const xieite::geometry::Point end) noexcept
		: xieite::geometry::LineLike(start, end) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Segment& other) const noexcept {
			return (start == other.start) && (end == other.end) || (start == other.end) && (end == other.start);
		}
	};
}
