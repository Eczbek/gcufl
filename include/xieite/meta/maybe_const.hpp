#pragma once

#include <type_traits>
#include "../meta/copy_ref.hpp"

namespace xieite {
	template<typename T, bool cond>
	using maybe_const = xieite::copy_ref<T, std::conditional_t<cond, const std::remove_reference_t<T>, std::remove_const_t<std::remove_reference_t<T>>>>;
}
