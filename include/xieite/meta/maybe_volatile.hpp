#pragma once

#include <type_traits>
#include "../meta/copy_ref.hpp"

namespace xieite {
	template<typename T, bool cond>
	using maybe_volatile = xieite::copy_ref<T, std::conditional_t<cond, volatile std::remove_reference_t<T>, std::remove_volatile_t<std::remove_reference_t<T>>>>;
}
