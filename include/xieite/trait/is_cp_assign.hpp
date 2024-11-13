#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_cp_assign = std::is_copy_assignable_v<T>;
}
