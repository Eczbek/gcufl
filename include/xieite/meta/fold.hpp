#pragma once

#include <utility>

namespace XIEITE_DETAIL {
	template<auto fn, typename T>
	struct fold_helper {
		using type = T;

		template<typename U>
		XIEITE_DETAIL::fold_helper<fn, decltype(fn.template operator()<U, T>())> operator->*(const U&) const;
	};
}

namespace xieite {
	template<auto fn, typename T, typename... Ts>
	using fold = decltype((XIEITE_DETAIL::fold_helper<fn, T>()->*...->*std::declval<Ts>()))::type;
}
