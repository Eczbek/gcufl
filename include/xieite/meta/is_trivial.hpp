#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_trivial = std::is_trivial_v<T>;
}
