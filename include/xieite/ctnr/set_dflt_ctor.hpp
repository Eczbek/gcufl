#pragma once

namespace xieite {
	template<bool>
	struct maybe_dflt_ctor {};

	template<>
	struct maybe_dflt_ctor<false> {
		maybe_dflt_ctor() = delete;
		maybe_dflt_ctor(const xieite::maybe_dflt_ctor<false>&) = default;
		maybe_dflt_ctor(xieite::maybe_dflt_ctor<false>&&) = default;
		xieite::maybe_dflt_ctor<false>& operator=(const xieite::maybe_dflt_ctor<false>&) = default;
		xieite::maybe_dflt_ctor<false>& operator=(xieite::maybe_dflt_ctor<false>&&) = default;
	};
}
