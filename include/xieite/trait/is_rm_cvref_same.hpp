#pragma once

#include <concepts>
#include <type_traits>

namespace xieite {
	template<typename T, typename U>
	concept is_rm_cvref_same = std::same_as<std::remove_cvref_t<T>, std::remove_cvref_t<U>>;
}
