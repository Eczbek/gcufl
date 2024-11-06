#pragma once

#include "../meta/is_spec_of.hpp"

namespace xieite {
	template<template<typename...> typename M, typename T>
	concept is_template_of = xieite::is_spec_of<T, M>;
}
