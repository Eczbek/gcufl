#pragma once

#include <type_traits>

namespace xieite {
	template<typename T, bool cond>
	using set_lvalue_ref = std::conditional_t<cond, std::add_lvalue_reference_t<std::remove_reference_t<T>>, std::remove_reference_t<T>>;
}
