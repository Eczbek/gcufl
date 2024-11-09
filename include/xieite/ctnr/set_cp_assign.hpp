#pragma once

namespace xieite {
	template<bool>
	struct maybe_cp_assign {};

	template<>
	struct maybe_cp_assign<false> {
		maybe_cp_assign() = default;
		maybe_cp_assign(const xieite::maybe_cp_assign<false>&) = default;
		maybe_cp_assign(xieite::maybe_cp_assign<false>&&) = default;
		auto operator=(const xieite::maybe_cp_assign<false>&) = delete;
		xieite::maybe_cp_assign<false>& operator=(xieite::maybe_cp_assign<false>&&) = default;
	};
}
