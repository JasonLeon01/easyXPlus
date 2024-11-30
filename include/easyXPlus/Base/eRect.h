#pragma once

namespace easyXPlus {
	class eRect {
	public:
		int x;
		int y;
		int width;
		int height;

		eRect(int x, int y, int width, int height);
		eRect(const eRect& other);
		eRect(const eRect&& other);
	};
}