#pragma once

#include <type_traits>
#include "../ctnr/maybe_default_ctor.hpp"

namespace xieite {
	template<typename T>
	using same_default_ctor = xieite::maybe_default_ctor<std::is_default_constructible_v<T>>;
}
