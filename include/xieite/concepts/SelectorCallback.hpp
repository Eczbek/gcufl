#pragma once
#include <concepts> // std::convertible_to
#include <type_traits> // std::invoke_result_t

namespace xieite::concepts {
	template<typename Invocable, typename Argument>
	concept SelectorCallback = std::convertible_to<std::invoke_result_t<Invocable, Argument>, bool>;
}
