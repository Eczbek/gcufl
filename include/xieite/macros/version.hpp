#ifndef XIEITE_HEADER_MACROS_VERSION
#	define XIEITE_HEADER_MACROS_VERSION

#	define XIEITE_VERSION_MAJOR 6
#	define XIEITE_VERSION_MINOR 33
#	define XIEITE_VERSION_PATCH 0

#	define XIEITE_VERSION_LEAST(...) XIEITE_INTERNAL_VERSION_SELECT(__VA_ARGS__, XIEITE_INTERNAL_VERSION_LEAST_OVERLOAD(__VA_ARGS__), XIEITE_INTERNAL_VERSION_LEAST_OVERLOAD(__VA_ARGS__, 0), XIEITE_INTERNAL_VERSION_LEAST_OVERLOAD(__VA_ARGS__, 0, 0))
#	define XIEITE_VERSION_MOST(...) XIEITE_INTERNAL_VERSION_SELECT(__VA_ARGS__, XIEITE_INTERNAL_VERSION_MOST_OVERLOAD(__VA_ARGS__), XIEITE_INTERNAL_VERSION_MOST_OVERLOAD(__VA_ARGS__, 0), XIEITE_INTERNAL_VERSION_MOST_OVERLOAD(__VA_ARGS__, 0, 0))
#	define XIEITE_INTERNAL_VERSION_SELECT(_1, _2, _3, overload, ...) overload
#	define XIEITE_INTERNAL_VERSION_LEAST_OVERLOAD(major, minor, patch) ((XIEITE_VERSION_MAJOR > (major)) || (XIEITE_VERSION_MAJOR == (major)) && ((XIEITE_VERSION_MINOR > (minor) || (XIEITE_VERSION_MINOR == (minor)) && (XIEITE_VERSION_PATCH >= (patch)))))
#	define XIEITE_INTERNAL_VERSION_MOST_OVERLOAD(major, minor, patch) ((XIEITE_VERSION_MAJOR < (major)) || (XIEITE_VERSION_MAJOR == (major)) && ((XIEITE_VERSION_MINOR < (minor) || (XIEITE_VERSION_MINOR == (minor)) && (XIEITE_VERSION_PATCH <= (patch)))))

#endif
