#pragma once

#include <type_traits>

namespace xieite {
	template<typename T, typename U>
	concept is_assign = std::is_assignable_v<T, U>;
}
