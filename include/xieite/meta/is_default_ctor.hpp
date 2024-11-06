#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_default_constructible = std::is_default_constructible_v<T>;
}
