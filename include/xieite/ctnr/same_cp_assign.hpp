#pragma once

#include <type_traits>
#include "../ctnr/set_cp_assign.hpp"

namespace xieite {
	template<typename T>
	using same_cp_assign = xieite::set_cp_assign<std::is_copy_assignable_v<T>>;
}
