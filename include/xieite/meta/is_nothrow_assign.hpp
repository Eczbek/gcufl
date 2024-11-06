#pragma once

#include <type_traits>

namespace xieite {
	template<typename T, typename U>
	concept is_nothrow_assign = std::is_nothrow_assignable_v<T, U>;
}
