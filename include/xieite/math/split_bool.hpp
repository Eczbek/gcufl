#pragma once

namespace xieite {
	[[nodiscard]] constexpr int split_bool(bool value) noexcept {
		return value * 2 - 1;
	}
}
