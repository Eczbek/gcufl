#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_triv = std::is_triv_v<T>;
}
