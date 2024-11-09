#pragma once

#include "../meta/is_spec.hpp"

namespace xieite {
	template<typename T, template<typename> typename... Ms>
	concept is_spec_all = (... && xieite::is_spec<T, Ms>);
}
