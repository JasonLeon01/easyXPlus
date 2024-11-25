#include <easyXPlus/Base/eRGBA.h>

namespace easyXPlus {
	const eRGBA eRGBA::Black = eRGBA(0, 0, 0);
	const eRGBA eRGBA::White = eRGBA(255, 255, 255);
	const eRGBA eRGBA::Red = eRGBA(255, 0, 0);
	const eRGBA eRGBA::Green = eRGBA(0, 255, 0);
	const eRGBA eRGBA::Blue = eRGBA(0, 0, 255);
	const eRGBA eRGBA::Yellow = eRGBA(255, 255, 0);
	const eRGBA eRGBA::Cyan = eRGBA(0, 255, 255);
	const eRGBA eRGBA::Magenta = eRGBA(255, 0, 255);
	const eRGBA eRGBA::Gray = eRGBA(128, 128, 128);
	const eRGBA eRGBA::LightGray = eRGBA(192, 192, 192);
	const eRGBA eRGBA::DarkGray = eRGBA(64, 64, 64);
	const eRGBA eRGBA::LightRed = eRGBA(255, 128, 128);
	const eRGBA eRGBA::DarkRed = eRGBA(128, 0, 0);
	const eRGBA eRGBA::LightGreen = eRGBA(128, 255, 128);
	const eRGBA eRGBA::DarkGreen = eRGBA(0, 128, 0);
	const eRGBA eRGBA::LightBlue = eRGBA(128, 128, 255);
	const eRGBA eRGBA::DarkBlue = eRGBA(0, 0, 128);
	const eRGBA eRGBA::Transparent = eRGBA(255, 255, 255);

	const bool eRGBA::operator==(const eRGBA& other) const {
		return R == other.R && G == other.G && B == other.B && A == other.A;
	}

	const bool eRGBA::operator!=(const eRGBA& other) const {
		return !(*this == other);
	}

	COLORREF eRGBA::ToColorRef() const {
		return RGB(B, G, R);
	}
}