#pragma once

#include "../pp/fwd.hpp"

#define XIEITE_LIFT(...) XIEITE_DETAIL_LIFT(, ..., __VA_ARGS__)
#define XIEITE_LIFT_LOCAL(...) XIEITE_DETAIL_LIFT(&, ..., __VA_ARGS__)
#define XIEITE_LIFT_ONE(...) XIEITE_DETAIL_LIFT(,, __VA_ARGS__)
#define XIEITE_LIFT_ONE_LOCAL(...) XIEITE_DETAIL_LIFT(&,, __VA_ARGS__)

// Temporarily avoiding `XIEITE_ARROW()` until it is fixed
#define XIEITE_DETAIL_LIFT(capture, ellipsis, ...) \
	[capture][[nodiscard]](auto&& ellipsis XIEITE_DETAIL_ARGS) \
	noexcept(noexcept(__VA_ARGS__(XIEITE_FWD(XIEITE_DETAIL_ARGS) ellipsis))) \
	-> decltype(__VA_ARGS__(XIEITE_FWD(XIEITE_DETAIL_ARGS) ellipsis)) \
	{ return __VA_ARGS__(XIEITE_FWD(XIEITE_DETAIL_ARGS) ellipsis); }
