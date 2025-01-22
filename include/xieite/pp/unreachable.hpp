#pragma once

#include "../pp/lang.hpp"

#if XIEITE_LANG_LEAST(CPP, 2023)
#	include <utility>

#	define XIEITE_UNREACHABLE() (::std::unreachable())
#elif XIEITE_LANG_LEAST(C, 2023)
#	include <stddef.h>

#	define XIEITE_UNREACHABLE() (unreachable())
#else
#	include "../pp/cplr.hpp"

#	if XIEITE_CPLR_TYPE_GCC || XIEITE_CPLR_TYPE_CLANG
#		define XIEITE_UNREACHABLE() (__builtin_unreachable())
#	elif XIEITE_CPLR_TYPE_MSVC
#		define XIEITE_UNREACHABLE() (__assume(false))
#	else
#		include "../pp/attr.hpp"

XIEITE_ATTR_NORET inline void XIEITE_DETAIL_unreachable() {}

#		define XIEITE_UNREACHABLE() (XIEITE_DETAIL_unreachable())
#	endif
#endif

// Thanks to eightfold (https://github.com/8ightfold) for original code
