#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_trivial_copy = std::is_trivially_copyable_v<T>;
}
