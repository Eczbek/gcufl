#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_triv_ctor = std::is_trivially_constructible_v<T>;
}
