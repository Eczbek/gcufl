#pragma once

#include <chrono>
#include <tuple>
#include "../trait/is_dur.hpp"

namespace xieite {
	template<xieite::is_dur T, xieite::is_dur... Us>
	[[nodiscard]] constexpr std::tuple<Us...> conv_dur(T dur) noexcept {
		std::tuple<Us...> results;
		(..., ([&dur, &results] -> void {
			const Us result = std::chrono::duration_cast<Us>(dur);
			std::get<Us>(results) = result;
			dur -= result;
		})());
		return results;
	}
}

// Stolen from orlac (https://github.com/vorlac)
