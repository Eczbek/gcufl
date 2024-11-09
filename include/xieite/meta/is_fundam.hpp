#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_fundam = std::is_fundamental_v<T>;
}
