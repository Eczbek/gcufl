#pragma once

#include <type_traits>
#include "../ctnr/maybe_copy_ctor.hpp"

namespace xieite {
	template<typename T>
	using same_copy_ctor = xieite::maybe_copy_ctor<std::is_copy_constructible_v<T>>;
}
