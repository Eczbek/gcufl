#pragma once

#include <type_traits>
#include "../ctnr/set_dflt_ctor.hpp"

namespace xieite {
	template<typename T>
	using same_dflt_ctor = xieite::set_dflt_ctor<std::is_default_constructible_v<T>>;
}
