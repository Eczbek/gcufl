#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_triv_cp_ctor = std::is_trivially_copy_constructible_v<T>;
}
