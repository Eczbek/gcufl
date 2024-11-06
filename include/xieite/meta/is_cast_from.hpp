#pragma once

#include <concepts>

namespace xieite {
	template<typename T, typename U>
	concept is_cast_from = std::convertible_to<U, T>;
}
