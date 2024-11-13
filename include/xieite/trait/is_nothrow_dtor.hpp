#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_nothrow_destructible = std::is_nothrow_destructible_v<T>;
}
