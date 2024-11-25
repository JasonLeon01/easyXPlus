#pragma once
#include <easyx.h>

namespace easyXPlus {
	class eRGBA {
	public:
		eRGBA() : R(0), G(0), B(0), A(255) {}
		eRGBA(int r, int g, int b, int a = 255) : R(r), G(g), B(b), A(a) {}

		int R;
		int G;
		int B;
		int A;

		const bool operator==(const eRGBA& other) const;
		const bool operator!=(const eRGBA& other) const;

		COLORREF ToColorRef() const;

		static const eRGBA Black;
		static const eRGBA White;
		static const eRGBA Red;
		static const eRGBA Green;
		static const eRGBA Blue;
		static const eRGBA Yellow;
		static const eRGBA Cyan;
		static const eRGBA Magenta;
		static const eRGBA Gray;
		static const eRGBA LightGray;
		static const eRGBA DarkGray;
		static const eRGBA LightRed;
		static const eRGBA DarkRed;
		static const eRGBA LightGreen;
		static const eRGBA DarkGreen;
		static const eRGBA LightBlue;
		static const eRGBA DarkBlue;
		static const eRGBA Transparent;
	};
}