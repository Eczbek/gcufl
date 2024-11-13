#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_member_obj_ptr = std::is_member_object_pointer_v<T>;
}
