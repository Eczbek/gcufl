#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_trivial_move_assign = std::is_trivially_move_assignable_v<T>;
}
