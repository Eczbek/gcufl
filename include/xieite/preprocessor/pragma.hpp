#pragma once

#include "../preprocessor/compiler.hpp"
#include "../preprocessor/language.hpp"
#include "../preprocessor/stringify.hpp"

#if (XIEITE_LANGUAGE_CPP >= XIEITE_LANGUAGE_CPP_2011) || (XIEITE_LANGUAGE_C >= XIEITE_LANGUAGE_C_1999)
#	define XIEITE_PRAGMA(...) _Pragma(XIEITE_STRINGIFY(__VA_ARGS__))
#elif XIEITE_COMPILER_TYPE_MSVC
#	define XIEITE_PRAGMA(...) __pragma(__VA_ARGS__)
#else
#	define XIEITE_PRAGMA(...)
#endif
