#pragma once

#include "../meta/is_spec_of.hpp"

namespace xieite {
	template<typename T, template<typename> typename... Ms>
	concept is_spec_of_all = (... && xieite::is_spec_of<T, Ms>);
}
