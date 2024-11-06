#pragma once

#include <type_traits>
#include "../meta/copy_const.hpp"
#include "../meta/copy_volatile.hpp"

namespace xieite {
	template<typename T, typename U>
	using collapse_ref = xieite::copy_volatile<T, xieite::copy_const<T, std::conditional_t<std::is_lvalue_reference_v<T>, std::add_lvalue_reference_t<U>, std::add_rvalue_reference_t<U>>>>;
}
