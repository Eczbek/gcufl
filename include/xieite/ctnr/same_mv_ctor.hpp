#pragma once

#include <type_traits>
#include "../ctnr/set_mv_ctor.hpp"

namespace xieite {
	template<typename T>
	using same_mv_ctor = xieite::set_mv_ctor<std::is_move_constructible_v<T>>;
}
