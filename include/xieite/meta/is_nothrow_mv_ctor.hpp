#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_nothrow_mv_ctor = std::is_nothrow_move_constructible_v<T>;
}
