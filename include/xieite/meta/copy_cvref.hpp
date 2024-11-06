#pragma once

#include "../meta/copy_const.hpp"
#include "../meta/copy_ref.hpp"
#include "../meta/copy_volatile.hpp"

namespace xieite {
	template<typename T, typename U>
	using copy_cvref = xieite::copy_ref<T, xieite::copy_volatile<T, xieite::copy_const<T, U>>>;
}
