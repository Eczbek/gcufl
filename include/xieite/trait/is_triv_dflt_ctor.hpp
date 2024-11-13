#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_triv_dflt_ctor = std::is_trivially_default_constructible_v<T>;
}
