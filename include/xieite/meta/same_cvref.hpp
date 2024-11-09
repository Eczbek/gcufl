#pragma once

#include "../meta/same_const.hpp"
#include "../meta/same_ref.hpp"
#include "../meta/same_volat.hpp"

namespace xieite {
	template<typename T, typename U>
	using same_cvref = xieite::same_ref<T, xieite::same_volat<T, xieite::same_const<T, U>>>;
}
