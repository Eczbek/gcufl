#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_mv_assign = std::is_move_assignable_v<T>;
}
