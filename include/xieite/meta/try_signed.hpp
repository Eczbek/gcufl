#pragma once

#include <type_traits>
#include "../meta/is_uint.hpp"

namespace xieite {
	template<typename T>
	using try_signed = std::conditional_t<xieite::is_uint<T>, std::make_signed<T>, std::type_identity<T>>::type;
}
