#pragma once

#include "../meta/is_spec.hpp"

namespace xieite {
	template<template<typename...> typename M, typename T>
	concept is_template = xieite::is_spec<T, M>;
}
