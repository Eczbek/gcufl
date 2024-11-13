#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_nothrow_dflt_ctor = std::is_nothrow_default_constructible_v<T>;
}
