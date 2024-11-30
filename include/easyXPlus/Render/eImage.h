#pragma once
#include <easyx.h>
#include <easyXPlus/Base/eRect.h>
#include <easyXPlus/Base/eRGBA.h>

namespace easyXPlus {
	class eImage : public IMAGE{
	public:
		eImage(int _width  = 0, int _height = 0);

		void Clear(eRGBA color);

		static void Render(IMAGE* dstimg, int x, int y, IMAGE* srcimg, BYTE opacity = 255);
		static void Render(IMAGE* dstimg, int x, int y, IMAGE* srcimg, eRect cropRect, BYTE opacity = 255);
	};
}