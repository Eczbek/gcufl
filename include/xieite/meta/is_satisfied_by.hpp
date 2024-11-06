#pragma once

namespace xieite {
	template<auto fn, typename... Ts>
	concept is_satisfied_by = requires { fn.template operator()<Ts...>(); };
}
