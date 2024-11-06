#pragma once

#include <chrono>
#include <tuple>
#include "../meta/is_duration.hpp"

namespace xieite {
	template<xieite::is_duration T, xieite::is_duration... Us>
	[[nodiscard]] constexpr std::tuple<Us...> convert_duration(T duration) noexcept {
		std::tuple<Us...> results;
		(..., ([&duration, &results] -> void {
			const Us result = std::chrono::duration_cast<Us>(duration);
			std::get<Us>(results) = result;
			duration -= result;
		})());
		return results;
	}
}

// Stolen from orlac (https://github.com/vorlac)
