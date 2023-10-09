#ifndef XIEITE_HEADER__MACROS__RESTRICT
#	define XIEITE_HEADER__MACROS__RESTRICT

#	include "../macros/compiler_type.hpp"

#	if XIEITE__COMPILER_TYPE__GCC
#		define XIEITE__RESTRICT __restrict__
#	elif XIEITE__COMPILER_TYPE__LLVM || XIEITE__COMPILER_TYPE__MSVC
#		define XIEITE__RESTRICT __restrict
#	else
#		define XIEITE__RESTRICT
#	endif

#endif

// Thanks to eightfold for original code
