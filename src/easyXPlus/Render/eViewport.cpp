#include <easyXPlus/Render/eViewport.h>
#include <easyXPlus/Render/eBitmap.h>

namespace easyXPlus {
	eViewport* eViewport::DefaultViewport = new eViewport(eRect(0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)));

	eViewport::eViewport(eRect rect, int _z) {
		position = { rect.x, rect.y, _z };
		ox = 0;
		oy = 0;
		flashCount = 0;
		flashDuration = 0;
		eImage(rect.width, rect.height);
	}

	void eViewport::Flash(eRGBA color, int duration) {
		flashCount = 0;
		flashDuration = duration;
		flashColor = color;
	}

	void eViewport::Update() {
		eImage::Render(nullptr, position.x, position.y, this);
		eRGBA color = flashColor;
		flashColor.A = (flashDuration - flashCount) * flashColor.A / flashDuration;
		if (flashCount < flashDuration) {
			++flashCount;
		}
		eBitmap::FillRect(this, eRect(0, 0, this->getwidth(), this->getheight()), flashColor);
	}
}