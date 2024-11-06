#pragma once

#include "../meta/maybe_const.hpp"
#include "../meta/type_list.hpp"
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"

namespace xieite {
	template<typename F, typename... Args>
	constexpr auto try_const_args(F&& fn, Args&&... args)
	XIEITE_ARROW(
		xieite::type_list<Args...>
		::template transform<
			1,
			[]<typename Arg, typename... Rest> {
				return std::type_identity<
					std::conditional_t<
						xieite::type_list<Args...>
						::template slice<sizeof...(Rest) + 1>
						::template prepend<F, Rest..., xieite::maybe_const<Arg, true>>
						::template to<std::is_invocable>
						::value,
						xieite::maybe_const<Arg, true>,
						Arg
					>
				>();
			}
		>
		::apply(
			[&fn, &args...]<typename... ConstArgs>
			XIEITE_ARROW(std::invoke(XIEITE_FWD(fn), std::forward_like<ConstArgs>(args)...))
		)
	)
}
