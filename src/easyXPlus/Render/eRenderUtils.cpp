#include <easyXPlus/Render/eRenderUtils.h>

namespace easyXPlus {
	void eRenderUtils::Render(IMAGE* dstimg, int x, int y, IMAGE* srcimg, int opacity) {
		HDC dstDC = GetImageHDC(dstimg);
		HDC srcDC = GetImageHDC(srcimg);
		int w = srcimg->getwidth();
		int h = srcimg->getheight();

		BLENDFUNCTION bf = { AC_SRC_OVER, 0, opacity, AC_SRC_ALPHA };
		AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);
	}

	void eRenderUtils::Render(IMAGE* dstimg, int x, int y, IMAGE* srcimg, eRect cropRect, int opacity) {
		HDC dstDC = GetImageHDC(dstimg);
		HDC srcDC = GetImageHDC(srcimg);
		int w = cropRect.GetWidth();
		int h = cropRect.GetHeight();

		BLENDFUNCTION bf = { AC_SRC_OVER, 0, opacity, AC_SRC_ALPHA };
		AlphaBlend(dstDC, x, y, w, h, srcDC, cropRect.GetX(), cropRect.GetY(), w, h, bf);
	}
}