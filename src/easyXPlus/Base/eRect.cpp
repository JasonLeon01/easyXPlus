#include <easyXPlus/Base/eRect.h>

namespace easyXPlus {
	eRect::eRect(int x, int y, int w, int h) {
		this->x = x;
		this->y = y;
		this->width = w;
		this->height = h;
	}

	eRect::eRect(const eRect& other) {
		x = other.x;
		y = other.y;
		width = other.width;
		height = other.height;
	}

	eRect::eRect(const eRect&& other) {
		x = other.x;
		y = other.y;
		width = other.width;
		height = other.height;
	}
}