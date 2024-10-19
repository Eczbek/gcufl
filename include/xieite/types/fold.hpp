#pragma once

namespace XIEITE_DETAIL {
	template<auto transformer, typename Result>
	struct FoldHelper
	: Result {
		template<typename Next>
		FoldHelper<transformer, decltype(transformer.template operator()<Next::type, Result::type>())> operator->*(Next) const;
	};
}

namespace xieite::types {
	template<auto transformer, typename First, typename... Rest>
	using Fold = decltype((XIEITE_DETAIL::FoldHelper<transformer, std::type_identity<First>>()->*...->*std::type_identity<Rest>()))::type;
}
