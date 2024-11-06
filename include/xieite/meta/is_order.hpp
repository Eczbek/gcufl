#pragma once

#include <compare>
#include <type_traits>
#include "../meta/is_same_as_any.hpp"

namespace xieite {
	template<typename T>
	concept is_order = xieite::is_same_as_any<std::remove_cv_t<T>, std::strong_ordering, std::weak_ordering, std::partial_ordering>;
}
