#pragma once

namespace xieite {
	template<bool>
	struct maybe_mv_assign {};

	template<>
	struct maybe_mv_assign<false> {
		maybe_mv_assign() = default;
		maybe_mv_assign(const xieite::maybe_mv_assign<false>&) = default;
		maybe_mv_assign(xieite::maybe_mv_assign<false>&&) = default;
		xieite::maybe_mv_assign<false>& operator=(const xieite::maybe_mv_assign<false>&) = default;
		auto operator=(xieite::maybe_mv_assign<false>&&) = delete;
	};
}
