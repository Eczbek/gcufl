#pragma once

#include <type_traits>
#include "../ctnr/set_mv_assign.hpp"

namespace xieite {
	template<typename T>
	using same_mv_assign = xieite::set_mv_assign<std::is_move_assignable_v<T>>;
}
