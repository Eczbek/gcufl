#pragma once

#if __has_include(<unistd.h>)
#	include <unistd.h>
#endif

#define XIEITE_UNIX_POSIX 0
#define XIEITE_UNIX_X_OPEN 0
#define XIEITE_UNIX_LINUX_STANDARD_BASE 0

#define XIEITE_UNIX_POSIX_1988 198808
#define XIEITE_UNIX_POSIX_1990 199009
#define XIEITE_UNIX_POSIX_1992 199209
#define XIEITE_UNIX_POSIX_1993 199309
#define XIEITE_UNIX_POSIX_1996 199506
#define XIEITE_UNIX_POSIX_2001 200112
#define XIEITE_UNIX_POSIX_2008 200809
#define XIEITE_UNIX_X_OPEN_1989 3
#define XIEITE_UNIX_X_OPEN_1992 4
#define XIEITE_UNIX_X_OPEN_1995 5
#define XIEITE_UNIX_X_OPEN_1998 500
#define XIEITE_UNIX_X_OPEN_2003 600
#define XIEITE_UNIX_X_OPEN_2008 700
#define XIEITE_UNIX_LINUX_STANDARD_BASE_1_0 10
#define XIEITE_UNIX_LINUX_STANDARD_BASE_1_1 11
#define XIEITE_UNIX_LINUX_STANDARD_BASE_1_2 12
#define XIEITE_UNIX_LINUX_STANDARD_BASE_1_3 13
#define XIEITE_UNIX_LINUX_STANDARD_BASE_2_0 20
#define XIEITE_UNIX_LINUX_STANDARD_BASE_2_1 21
#define XIEITE_UNIX_LINUX_STANDARD_BASE_3_0 30
#define XIEITE_UNIX_LINUX_STANDARD_BASE_3_1 31
#define XIEITE_UNIX_LINUX_STANDARD_BASE_3_2 32
#define XIEITE_UNIX_LINUX_STANDARD_BASE_4_0 40
#define XIEITE_UNIX_LINUX_STANDARD_BASE_4_1 41
#define XIEITE_UNIX_LINUX_STANDARD_BASE_5_0 50

#ifdef _POSIX_VERSION
#	undef XIEITE_UNIX_POSIX

#	if defined(_POSIX2_C_VERSION) && (_POSIX2_C_VERSION > _POSIX_VERSION)
#		define XIEITE_UNIX_POSIX _POSIX2_C_VERSION
#	else
#		define XIEITE_UNIX_POSIX _POSIX_VERSION
#endif

#ifdef _XOPEN_VERSION
#	undef XIEITE_UNIX_X_OPEN

#	if (_XOPEN_VERSION >= 4) && defined(_XOPEN_UNIX)
#		define XIEITE_UNIX_X_OPEN 5
#	else
#		define XIEITE_UNIX_X_OPEN _XOPEN_VERSION
#	endif
#endif

#ifdef __LSB_VERSION__
#	undef XIEITE_UNIX_LINUX_STANDARD_BASE
#	define XIEITE_UNIX_LINUX_STANDARD_BASE __LSB_VERSION__
#else

// https://sourceforge.net/p/predef/wiki/Standards/
