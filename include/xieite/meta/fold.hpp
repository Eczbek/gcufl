#pragma once

#include <type_traits>

namespace XIEITE_DETAIL {
	template<auto fn, typename T>
	struct fold_helper {
		using type = T;

		template<typename U>
		XIEITE_DETAIL::fold_helper<fn, decltype(fn.template operator()<U, T>())> operator->*(std::type_identity<U>) const;
	};
}

namespace xieite {
	template<auto fn, typename T, typename... Ts>
	using fold = decltype((XIEITE_DETAIL::fold_helper<fn, T>()->*...->*std::type_identity<Ts>()))::type;
}
