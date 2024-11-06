#pragma once

#include <type_traits>
#include "../ctnr/maybe_move_assign.hpp"

namespace xieite {
	template<typename T>
	using same_move_assign = xieite::maybe_move_assign<std::is_move_assignable_v<T>>;
}
