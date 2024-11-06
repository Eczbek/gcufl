#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_trivial_copy_assign = std::is_trivially_copy_assignable_v<T>;
}
