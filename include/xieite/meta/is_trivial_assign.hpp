#pragma once

#include <type_traits>

namespace xieite {
	template<typename T, typename U>
	concept is_trivial_assign = std::is_trivially_assignable_v<T, U>;
}
