#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_move_ctor = std::is_move_constructible_v<T>;
}
