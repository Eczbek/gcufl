#pragma once

namespace xieite {
	template<bool>
	struct maybe_mv_ctor {};

	template<>
	struct maybe_mv_ctor<false> {
		maybe_mv_ctor() = default;
		maybe_mv_ctor(const xieite::maybe_mv_ctor<false>&) = default;
		maybe_mv_ctor(xieite::maybe_mv_ctor<false>&&) = delete;
		xieite::maybe_mv_ctor<false>& operator=(const xieite::maybe_mv_ctor<false>&) = default;
		xieite::maybe_mv_ctor<false>& operator=(xieite::maybe_mv_ctor<false>&&) = default;
	};
}
