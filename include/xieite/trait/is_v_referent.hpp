#pragma once

#include "../fn/visitor.hpp"
#include "../meta/t.hpp"
#include "../trait/rm_cvref.hpp"

namespace xieite {
	template<typename T>
	concept is_v_referent = xieite::visitor(
		[](...) { return false; },
		[]<typename U>(xieite::t<volatile U*>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args...) volatile noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args..., ...) volatile noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args...) const volatile noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args..., ...) const volatile noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args...) volatile & noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args..., ...) volatile & noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args...) const volatile & noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args...) volatile && noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args..., ...) volatile && noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args...) const volatile && noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)>) { return true; }
	)(xieite::t<xieite::rm_cvref<T>>());
}
