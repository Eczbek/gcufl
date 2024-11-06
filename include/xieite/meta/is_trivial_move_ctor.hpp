#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_trivial_move_ctor = std::is_trivially_move_constructible_v<T>;
}
