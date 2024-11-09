#pragma once

#include <type_traits>
#include "../meta/same_ref.hpp"

namespace xieite {
	template<typename T, bool cond>
	using set_ptr = xieite::same_ref<T, std::conditional_t<cond, std::remove_pointer_t<std::remove_reference_t<T>>*, std::remove_pointer_t<std::remove_reference_t<T>>>>;
}
