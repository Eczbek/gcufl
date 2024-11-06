#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_unique_obj_repr = std::has_unique_object_representations_v<T>;
}
