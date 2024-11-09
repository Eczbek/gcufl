#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_triv_dtor = std::is_trivially_destructible_v<T>;
}
