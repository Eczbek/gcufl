#pragma once

#include <type_traits>
#include "../ctnr/maybe_copy_assign.hpp"

namespace xieite {
	template<typename T>
	using same_move_ctor = xieite::maybe_move_ctor<std::is_move_constructible_v<T>>;
}
