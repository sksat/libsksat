#ifndef SKSAT_COLOR_HPP_
#define SKSAT_COLOR_HPP_

#include <sksat/common.hpp>

namespace sksat {

union rgb24 {
	rgb24() : value(0x00) {}
	rgb24(const uint32_t &col) : value(col) {}
	rgb24(const uint8_t &r, const uint8_t &g, const uint8_t &b) : r(r), g(g), b(b) {}
	struct {
		uint8_t r,g,b;
	};
	uint32_t value : 24;
};

union rgba32 {
	rgba32() : value(0x00) {}
	rgba32(const uint32_t &col) : value(col) {}
	rgba32(const uint8_t &r, const uint8_t &g, const uint8_t &b) : r(r), g(g), b(b), a(0x00) {}
	rgba32(const uint8_t &r, const uint8_t &g, const uint8_t &b, const uint8_t &a) : r(r), g(g), b(b), a(a) {}
	struct {
		uint8_t r,g,b,a;
	};
	uint32_t value;
};


using rgb  = rgb24;
using rgba = rgba32;

using color= rgb;

}

#endif
