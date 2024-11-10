#pragma once

#include <chrono>
#include <cstdint>
#include "../math/pi.hpp"
#include "../pp/fn.hpp"
#include "../str/fixed_str.hpp"

namespace XIEITE_DETAIL {
	template<xieite::fixed_str type, auto to = [](auto x) { return x; }, auto from = [](auto x) { return x; }>
	struct base_unit {
		double value;

		template<auto other_to, auto other_from>
		[[nodiscard]] explicit(false) constexpr operator base_unit<type, other_to, other_from>() const noexcept {
			return base_unit<type, other_to, other_from>(other_from(to(this->value)));
		}
	};
}

namespace xieite::unit {
	// Lengths
	using qm = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 / 1e30), XIEITE_FN($0 * 1e30)>;
	using rm = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 / 1e27), XIEITE_FN($0 * 1e27)>;
	using ym = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 / 1e24), XIEITE_FN($0 * 1e24)>;
	using zm = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 / 1e21), XIEITE_FN($0 * 1e21)>;
	using am = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 / 1e18), XIEITE_FN($0 * 1e18)>;
	using fm = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 / 1e15), XIEITE_FN($0 * 1e15)>;
	using pm = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 / 1e12), XIEITE_FN($0 * 1e12)>;
	using nm = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 / 1e9), XIEITE_FN($0 * 1e9)>;
	using um = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 / 1e6), XIEITE_FN($0 * 1e6)>;
	using mm = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 / 1e3), XIEITE_FN($0 * 1e3)>;
	using cm = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 / 1e2), XIEITE_FN($0 * 1e2)>;
	using dm = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 / 1e1), XIEITE_FN($0 * 1e1)>;
	using m = XIEITE_DETAIL::base_unit<"length">;
	using dam = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 1e1), XIEITE_FN($0 / 1e1)>;
	using hm = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 1e2), XIEITE_FN($0 / 1e2)>;
	using km = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 1e3), XIEITE_FN($0 / 1e3)>;
	using Mm = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 1e6), XIEITE_FN($0 / 1e6)>;
	using Gm = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 1e9), XIEITE_FN($0 / 1e9)>;
	using Tm = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 1e12), XIEITE_FN($0 / 1e12)>;
	using Pm = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 1e15), XIEITE_FN($0 / 1e15)>;
	using Em = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 1e18), XIEITE_FN($0 / 1e18)>;
	using Zm = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 1e21), XIEITE_FN($0 / 1e21)>;
	using Ym = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 1e24), XIEITE_FN($0 / 1e24)>;
	using Rm = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 1e27), XIEITE_FN($0 / 1e27)>;
	using Qm = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 1e30), XIEITE_FN($0 / 1e30)>;
	using twips = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 0.0254 / 1440.0), XIEITE_FN($0 * 1440.0 / 0.0254)>;
	using thous = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 0.0000254), XIEITE_FN($0 / 0.0000254)>;
	using barleycorns = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 0.0254 / 3.0), XIEITE_FN($0 * 3.0 / 0.0254)>;
	using in = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 0.0254), XIEITE_FN($0 / 0.0254)>;
	using ft = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 / 0.3048), XIEITE_FN($0 * 0.3048)>;
	using yd = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 0.9144), XIEITE_FN($0 / 0.9144)>;
	using chains = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 20.1168), XIEITE_FN($0 / 20.1168)>;
	using furlongs = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 201.168), XIEITE_FN($0 / 201.168)>;
	using mi = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 1609.344), XIEITE_FN($0 / 1609.344)>;
	using leagues = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 4828.032), XIEITE_FN($0 / 4828.032)>;
	using fathoms = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 1.8288), XIEITE_FN($0 / 1.8288)>;
	using cables = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 185.2), XIEITE_FN($0 / 185.2)>;
	using nmi = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 1852.0), XIEITE_FN($0 / 1852.0)>;
	using nau_leagues = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 5556.0), XIEITE_FN($0 / 5556.0)>;
	using links = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 0.201168), XIEITE_FN($0 / 0.201168)>;
	using rods = XIEITE_DETAIL::base_unit<"length", XIEITE_FN($0 * 5.0292), XIEITE_FN($0 / 5.0292)>;
	using perches = xieite::unit::rods;
	using poles = xieite::unit::rods;
	using lugs = xieite::unit::rods;

	// Areas
	using qA = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 / 1e60), XIEITE_FN($0 * 1e60)>;
	using rA = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 / 1e54), XIEITE_FN($0 * 1e54)>;
	using yA = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 / 1e48), XIEITE_FN($0 * 1e48)>;
	using zA = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 / 1e42), XIEITE_FN($0 * 1e42)>;
	using aA = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 / 1e36), XIEITE_FN($0 * 1e36)>;
	using fA = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 / 1e30), XIEITE_FN($0 * 1e30)>;
	using pA = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 / 1e24), XIEITE_FN($0 * 1e24)>;
	using nA = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 / 1e18), XIEITE_FN($0 * 1e18)>;
	using uA = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 / 1e12), XIEITE_FN($0 * 1e12)>;
	using mA = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 / 1e6), XIEITE_FN($0 * 1e6)>;
	using cA = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 / 1e4), XIEITE_FN($0 * 1e4)>;
	using dA = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 / 1e2), XIEITE_FN($0 * 1e2)>;
	using A = XIEITE_DETAIL::base_unit<"area">;
	using daA = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 * 1e2), XIEITE_FN($0 / 1e2)>;
	using hA = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 * 1e4), XIEITE_FN($0 / 1e4)>;
	using kA = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 * 1e6), XIEITE_FN($0 / 1e6)>;
	using MA = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 * 1e12), XIEITE_FN($0 / 1e12)>;
	using GA = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 * 1e18), XIEITE_FN($0 / 1e18)>;
	using TA = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 * 1e24), XIEITE_FN($0 / 1e24)>;
	using PA = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 * 1e30), XIEITE_FN($0 / 1e30)>;
	using EA = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 * 1e36), XIEITE_FN($0 / 1e36)>;
	using ZA = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 * 1e42), XIEITE_FN($0 / 1e42)>;
	using YA = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 * 1e48), XIEITE_FN($0 / 1e48)>;
	using RA = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 * 1e54), XIEITE_FN($0 / 1e54)>;
	using QA = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 * 1e60), XIEITE_FN($0 / 1e60)>;
	using sq_in = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 / 1550.0031), XIEITE_FN($0 * 1550.0031)>;
	using sq_ft = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 / 10.7639104), XIEITE_FN($0 * 10.7639104)>;
	using sq_yd = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 * 0.83612736), XIEITE_FN($0 / 0.83612736)>;
	using sq_mi = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 * 2589988.110336), XIEITE_FN($0 / 2589988.110336)>;
	using sq_roods = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 * 1011.7141056), XIEITE_FN($0 / 1011.7141056)>;
	using ac = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 * 4046.8564224), XIEITE_FN($0 / 4046.8564224)>;
	using dma = xieite::unit::dA;
	using ca = xieite::unit::A;
	using da = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 * 1e1), XIEITE_FN($0 / 1e1)>;
	using a = xieite::unit::daA;
	using daa = XIEITE_DETAIL::base_unit<"area", XIEITE_FN($0 * 1e3), XIEITE_FN($0 / 1e3)>;
	using ha = xieite::unit::hA;

	// Volumes
	using qV = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 1e90), XIEITE_FN($0 * 1e90)>;
	using rV = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 1e81), XIEITE_FN($0 * 1e81)>;
	using yV = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 1e72), XIEITE_FN($0 * 1e72)>;
	using zV = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 1e63), XIEITE_FN($0 * 1e63)>;
	using aV = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 1e54), XIEITE_FN($0 * 1e54)>;
	using fV = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 1e45), XIEITE_FN($0 * 1e45)>;
	using pV = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 1e36), XIEITE_FN($0 * 1e36)>;
	using nV = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 1e27), XIEITE_FN($0 * 1e27)>;
	using uV = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 1e18), XIEITE_FN($0 * 1e18)>;
	using mV = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 1e9), XIEITE_FN($0 * 1e9)>;
	using cV = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 1e6), XIEITE_FN($0 * 1e6)>;
	using dV = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 1e3), XIEITE_FN($0 * 1e3)>;
	using V = XIEITE_DETAIL::base_unit<"volume">;
	using daV = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 * 1e3), XIEITE_FN($0 / 1e3)>;
	using hV = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 * 1e6), XIEITE_FN($0 / 1e6)>;
	using kV = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 * 1e9), XIEITE_FN($0 / 1e9)>;
	using MV = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 * 1e18), XIEITE_FN($0 / 1e18)>;
	using GV = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 * 1e27), XIEITE_FN($0 / 1e27)>;
	using TV = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 * 1e36), XIEITE_FN($0 / 1e36)>;
	using PV = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 * 1e45), XIEITE_FN($0 / 1e45)>;
	using EV = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 * 1e54), XIEITE_FN($0 / 1e54)>;
	using ZV = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 * 1e63), XIEITE_FN($0 / 1e63)>;
	using YV = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 * 1e72), XIEITE_FN($0 / 1e72)>;
	using RV = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 * 1e81), XIEITE_FN($0 / 1e81)>;
	using QV = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 * 1e90), XIEITE_FN($0 / 1e90)>;
	using cu_in = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 61023.744095), XIEITE_FN($0 * 61023.744095)>;
	using cu_ft = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 35.314666721), XIEITE_FN($0 * 35.314666721)>;
	using cu_yd = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 1.3079506193), XIEITE_FN($0 * 1.3079506193)>;
	using cu_mi = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 4168181825.440579584), XIEITE_FN($0 * 4168181825.440579584)>;
	using qL = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 1e33), XIEITE_FN($0 * 1e33)>;
	using rL = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 1e30), XIEITE_FN($0 * 1e30)>;
	using yL = xieite::unit::nV;
	using zL = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 1e24), XIEITE_FN($0 * 1e24)>;
	using aL = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 1e21), XIEITE_FN($0 * 1e21)>;
	using fL = xieite::unit::uV;
	using pL = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 1e15), XIEITE_FN($0 * 1e15)>;
	using nL = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 1e12), XIEITE_FN($0 * 1e12)>;
	using uL = xieite::unit::mV;
	using mL = xieite::unit::cV;
	using cL = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 1e5), XIEITE_FN($0 * 1e5)>;
	using dL = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 1e4), XIEITE_FN($0 * 1e4)>;
	using L = xieite::unit::dV;
	using daL = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 1e2), XIEITE_FN($0 * 1e2)>;
	using hL = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 1e1), XIEITE_FN($0 * 1e1)>;
	using kL = xieite::unit::V;
	using ML = xieite::unit::daV;
	using GL = xieite::unit::hV;
	using TL = xieite::unit::kV;
	using PL = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 * 1e12), XIEITE_FN($0 / 1e12)>;
	using EL = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 * 1e15), XIEITE_FN($0 / 1e15)>;
	using ZL = xieite::unit::MV;
	using YL = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 * 1e21), XIEITE_FN($0 / 1e21)>;
	using RL = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 * 1e24), XIEITE_FN($0 / 1e24)>;
	using QL = xieite::unit::GV;
	using fl_oz = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 33814.022702), XIEITE_FN($0 * 33814.022702)>;
	using gills = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 7039.0159455708), XIEITE_FN($0 * 7039.0159455708)>;
	using cups = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 3519.5079727854), XIEITE_FN($0 * 3519.5079727854)>;
	using pt = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 1759.7539863927), XIEITE_FN($0 * 1759.7539863927)>;
	using qt = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 879.87699319635), XIEITE_FN($0 * 879.87699319635)>;
	using gal = XIEITE_DETAIL::base_unit<"volume", XIEITE_FN($0 / 219.9691574), XIEITE_FN($0 * 219.9691574)>;

	// Angles
	using rad = XIEITE_DETAIL::base_unit<"angle">;
	using deg = XIEITE_DETAIL::base_unit<"angle", XIEITE_FN($0 * xieite::pi<double> / 180.0), XIEITE_FN($0 * 180.0 / xieite::pi<double>)>;

	// Temperature scales
	using K = XIEITE_DETAIL::base_unit<"temperature">;
	using C = XIEITE_DETAIL::base_unit<"temperature", XIEITE_FN($0 - 273.15), XIEITE_FN($0 + 273.15)>;
	using F = XIEITE_DETAIL::base_unit<"temperature", XIEITE_FN(($0 - 32.0) / 1.8 + 273.15), XIEITE_FN(($0 - 273.15) * 1.8 + 32.0)>;
	using R = XIEITE_DETAIL::base_unit<"temperature", XIEITE_FN($0 / 1.8), XIEITE_FN($0 * 1.8)>;

	// Durations
	using decades = std::chrono::duration<std::intmax_t, std::ratio<315569520>>;
	using centuries = std::chrono::duration<std::intmax_t, std::ratio<3155695200>>;
	using millenniums = std::chrono::duration<std::intmax_t, std::ratio<31556952000>>;
	using epochs = std::chrono::duration<std::intmax_t, std::ratio<31556952000000>>;
	using eons = std::chrono::duration<std::intmax_t, std::ratio<31556952000000000>>;
}
