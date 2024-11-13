#pragma once

namespace xieite {
	template<typename T, typename... Args>
	concept is_nothrow_brace_init = requires(Args... args) {
		requires(noexcept(T { args... }));
	};
}
