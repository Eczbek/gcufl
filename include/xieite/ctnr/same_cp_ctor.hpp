#pragma once

#include <type_traits>
#include "../ctnr/set_cp_ctor.hpp"

namespace xieite {
	template<typename T>
	using same_cp_ctor = xieite::set_cp_ctor<std::is_copy_constructible_v<T>>;
}
