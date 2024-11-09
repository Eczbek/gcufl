#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_nothrow_cp_ctor = std::is_nothrow_copy_constructible_v<T>;
}
