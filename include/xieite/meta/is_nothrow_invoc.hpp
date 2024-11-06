#pragma once

#include <type_traits>

namespace xieite {
	template<typename T, typename Sig>
	concept is_nothrow_invoc = ([]<typename Ret, typename... Args>(std::type_identity<Ret(Args...)>) -> bool {
		return std::is_nothrow_invocable_r_v<Ret, T, Args...>;
	})(std::type_identity<Sig>());
}
