#include <easyXPlus/Render/eImage.h>

namespace easyXPlus {
	eImage::eImage(int _width, int _height) {
		IMAGE(_width, _height);
	}

	void eImage::Clear(eRGBA color) {
		SetWorkingImage(this);
		cleardevice();
		SetWorkingImage(nullptr);
	}

	void eImage::Render(IMAGE* dstimg, int x, int y, IMAGE* srcimg, BYTE opacity) {
		HDC dstDC = GetImageHDC(dstimg);
		HDC srcDC = GetImageHDC(srcimg);
		int w = srcimg->getwidth();
		int h = srcimg->getheight();

		BLENDFUNCTION bf = { AC_SRC_OVER, 0, opacity, AC_SRC_ALPHA };
		AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);
	}

	void eImage::Render(IMAGE* dstimg, int x, int y, IMAGE* srcimg, eRect cropRect, BYTE opacity) {
		HDC dstDC = GetImageHDC(dstimg);
		HDC srcDC = GetImageHDC(srcimg);
		int w = cropRect.width;
		int h = cropRect.height;

		BLENDFUNCTION bf = { AC_SRC_OVER, 0, opacity, AC_SRC_ALPHA };
		AlphaBlend(dstDC, x, y, w, h, srcDC, cropRect.x, cropRect.y, w, h, bf);
	}
}