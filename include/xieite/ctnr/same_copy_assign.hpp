#pragma once

#include <type_traits>
#include "../ctnr/maybe_copy_assign.hpp"

namespace xieite {
	template<typename T>
	using same_copy_assign = xieite::maybe_copy_assign<std::is_copy_assignable_v<T>>;
}
