#pragma once

namespace easyXPlus {
	class eRect {
	public:
		eRect(int x, int y, int width, int height);
		eRect(const eRect& other);
		eRect(const eRect&& other);

		int GetX();
		int GetY();
		int GetWidth();
		int GetHeight();
	private:
		int x;
		int y;
		int width;
		int height;
	};
}