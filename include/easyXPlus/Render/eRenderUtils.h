#pragma once

#include <easyx.h>
#include <easyXPlus/Base/eRect.h>

namespace easyXPlus {
	class eRenderUtils {
	public:
		static void Render(IMAGE* dstimg, int x, int y, IMAGE* srcimg, int opacity = 255);
		static void Render(IMAGE* dstimg, int x, int y, IMAGE* srcimg, eRect cropRect, int opacity = 255);
	};
}