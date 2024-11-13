#pragma once

namespace xieite {
	template<typename>
	concept end = ([] -> void {
		static_assert(false, "too many arguments");
	}, false);
}
