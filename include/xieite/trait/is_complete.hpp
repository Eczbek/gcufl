#pragma once

namespace xieite {
	template<typename T, auto tag = [] {}>
	concept is_complete = (tag, !!sizeof(T));
}
