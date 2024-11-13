#pragma once

#include <cstddef>
#include <tuple>
#include <utility>
#include "../fn/unroll.hpp"
#include "../meta/tuple_fwd.hpp"
#include "../pp/fwd.hpp"
#include "../trait/is_spec.hpp"

namespace xieite {
	template<std::size_t start, std::size_t end = start, xieite::is_spec<std::tuple> Tuple0, xieite::is_spec<std::tuple> Tuple1 = std::tuple<>>
	[[nodiscard]] constexpr auto tuple_splice(Tuple0&& tuple0, Tuple1&& tuple1 = {}) noexcept {
		static constexpr std::size_t size = std::tuple_size_v<std::remove_cvref_t<Tuple0>>;
		static_assert(start <= size, "start index must be within tuple size");
		static_assert(end <= size, "end index must be within tuple size");
		return std::tuple_cat(
			xieite::unroll<start>([&tuple0]<std::size_t... i> {
				return std::forward_as_tuple(std::get<i>(std::move(tuple0))...);
			}),
			xieite::tuple_fwd(XIEITE_FWD(tuple1)),
			xieite::unroll<size - end>([&tuple0]<std::size_t... i> {
				return std::forward_as_tuple(std::get<end + i>(std::move(tuple0))...);
			})
		);
	}
}
