#pragma once

namespace xieite {
	template<typename T, typename... Args>
	concept is_brace_init = requires(Args... args) { T { args... }; };
}
