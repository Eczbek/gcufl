#pragma once

#include "../trait/set_noex.hpp"
#include "../trait/set_vlref_referent.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_vlref_noex = xieite::set_vlref_referent<qual, xieite::set_noex<qual, T>>;
}
