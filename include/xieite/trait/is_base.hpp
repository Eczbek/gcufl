#pragma once

#include <concepts>

namespace xieite {
	template<typename T, typename U>
	concept is_base = std::derived_from<U, T>;
}
