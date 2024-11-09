#pragma once

#include <type_traits>

namespace xieite {
	template<typename T, typename U>
	concept is_triv_assign = std::is_trivially_assignable_v<T, U>;
}
