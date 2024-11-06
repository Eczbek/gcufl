#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_ctor = std::is_constructible_v<T>;
}
