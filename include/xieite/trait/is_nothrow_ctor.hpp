#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_nothrow_ctor = std::is_nothrow_constructible_v<T>;
}
