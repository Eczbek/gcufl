#pragma once

#include "../pp/fwd.hpp"

namespace xieite {
	template<typename T>
	concept is_bool_testable = requires(T&& x) {
		static_cast<bool>(XIEITE_FWD(x));
		static_cast<bool>(!XIEITE_FWD(x));
		static_cast<void(*)(bool)>(nullptr)(XIEITE_FWD(x));
		static_cast<void(*)(bool)>(nullptr)(!XIEITE_FWD(x));
	};
}

// TODO: Check `operator&&` and `operator||` to best ability
// https://eel.is/c++draft/concept.booleantestable
