#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_nothrow_move_assign = std::is_nothrow_move_assignable_v<T>;
}
