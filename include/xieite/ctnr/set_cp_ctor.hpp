#pragma once

namespace xieite {
	template<bool>
	struct maybe_cp_ctor {};

	template<>
	struct maybe_cp_ctor<false> {
		maybe_cp_ctor() = default;
		maybe_cp_ctor(const xieite::maybe_cp_ctor<false>&) = delete;
		maybe_cp_ctor(xieite::maybe_cp_ctor<false>&&) = default;
		xieite::maybe_cp_ctor<false>& operator=(const xieite::maybe_cp_ctor<false>&) = default;
		xieite::maybe_cp_ctor<false>& operator=(xieite::maybe_cp_ctor<false>&&) = default;
	};
}
