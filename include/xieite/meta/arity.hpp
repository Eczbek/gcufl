#pragma once

#include <cstddef>
#include <tuple>
#include <type_traits>
#include "../meta/any.hpp"
#include "../meta/tuple_size.hpp"
#include "../pp/diag.hpp"
#include "../trait/is_tuple_like.hpp"

XIEITE_DIAG_PUSH_CLANG()
XIEITE_DIAG_OFF_CLANG("-Wunused-lambda-capture")

namespace xieite {
	template<typename T>
	constexpr std::size_t arity = ([] static -> std::size_t {
		if constexpr (xieite::is_tuple_like<T>) {
			return xieite::tuple_size<T>;
		} else if constexpr (std::is_aggregate_v<T>) {
			return ([](this auto self, std::size_t offset = 0, auto... curr) /* -> std::size_t */ {
				if constexpr (requires { T { curr..., xieite::any() }; } || requires { T { curr..., { xieite::any(), xieite::any() } }; }) {
					([&offset, curr...](this auto self, auto... pre) -> void {
						if constexpr (requires { T { curr..., pre..., xieite::any() }; }) {
							self(pre..., xieite::any());
						} else {
							([&offset, curr..., pre...](this auto self, auto... post) -> void {
								if constexpr (requires { T { curr..., { xieite::any(), xieite::any() }, post..., xieite::any() }; }) {
									self(post..., xieite::any());
								} else if constexpr (sizeof...(pre) != (sizeof...(post) + 1)) {
									([&offset, curr...](this auto self, auto... inner) -> void {
										if constexpr (requires { T { curr..., { inner..., xieite::any() } }; }) {
											self(inner..., xieite::any());
										} else {
											offset += sizeof...(inner) - 1;
										}
									})();
								}
							})();
						}
					})();
					return self(offset, curr..., xieite::any());
				} else {
					return sizeof...(curr) - offset;
				}
			})();
		} else {
			static_assert(false, "must not take arity of non-tuple-like nor aggregate type");
		}
	})();
}

XIEITE_DIAG_POP_CLANG()

// Algorithm stolen from lapinozz (https://github.com/lapinozz)
