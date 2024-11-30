#include <easyXPlus/Render/eBitmap.h>
#include <easyXPlus/Render/eFont.h>
#include <iostream>
#pragma comment( lib, "MSIMG32.LIB")

namespace easyXPlus {
	eBitmap::eBitmap(int width, int height) {
		bitmapContent = new eImage(width, height);
	}

	eBitmap::eBitmap(eImage* src) {
		bitmapContent = new eImage(src->getwidth(), src->getheight());
		eImage::Render(bitmapContent, 0, 0, src);
	}

	eBitmap::~eBitmap() {
		delete bitmapContent;
	}

	int eBitmap::GetWidth() {
		return bitmapContent->getwidth();
	}

	int eBitmap::GetHeight() {
		return bitmapContent->getheight();
	}

	eImage* eBitmap::GetImage() {
		return bitmapContent;
	}

	void eBitmap::Blit(int x, int y, eBitmap* srcBitmap, eRect srcRect, int opacity) {
		eImage::Render(bitmapContent, x, y, srcBitmap->bitmapContent, srcRect, opacity);
	}

	void eBitmap::FillRect(eRect rect, eRGBA color) {
		if (!bitmapContent) {
			std::cerr << "Error: bitmapContent is null!" << std::endl;
			return;
		}

		DWORD* pBuffer = GetImageBuffer(bitmapContent);
		if (!pBuffer) {
			std::cerr << "Error: Failed to get image buffer!" << std::endl;
			return;
		}

		int xStart = rect.x;
		int yStart = rect.y;
		int width = rect.width;
		int height = rect.height;

		DWORD argbColor = (color.A << 24) | (color.R << 16) | (color.G << 8) | color.B;

		for (int y = yStart; y < yStart + height; ++y) {
			for (int x = xStart; x < xStart + width; ++x) {
				pBuffer[y * bitmapContent->getwidth() + x] = argbColor;
			}
		}
	}

	void eBitmap::GradientFillRect(eRect rect, eRGBA color1, eRGBA color2, bool isVertical) {
		DWORD* pBuffer = GetImageBuffer(bitmapContent);

		if (!bitmapContent) {
			std::cerr << "Error: bitmapContent is null!" << std::endl;
			return;
		}

		if (!pBuffer) {
			std::cerr << "Error: Failed to get image buffer!" << std::endl;
			return;
		}

		int xStart = rect.x;
		int yStart = rect.y;
		int width = rect.width;
		int height = rect.height;

		for (int y = yStart; y < yStart + height; ++y) {
			for (int x = xStart; x < xStart + width; ++x) {
				float t = 0.0f;
				if (isVertical) {
					t = (float)(y - yStart) / (float)(height);
				}
				else {
					t = (float)(x - xStart) / (float)(width);
				}

				int r = (int)(color1.R + (color2.R - color1.R) * t);
				int g = (int)(color1.G + (color2.G - color1.G) * t);
				int b = (int)(color1.B + (color2.B - color1.B) * t);
				int a = (int)(color1.A + (color2.A - color1.A) * t);

				DWORD argbColor = (a << 24) | (r << 16) | (g << 8) | b;

				pBuffer[y * bitmapContent->getwidth() + x] = argbColor;
			}
		}
	}

	void eBitmap::Clear() {
		bitmapContent->Clear(eRGBA::Transparent);
	}

	void eBitmap::ClearRect(eRect rect) {
		DWORD* pBuffer = GetImageBuffer(bitmapContent);

		if (!bitmapContent) {
			std::cerr << "Error: bitmapContent is null!" << std::endl;
			return;
		}

		if (!pBuffer) {
			std::cerr << "Error: Failed to get image buffer!" << std::endl;
			return;
		}

		int xStart = rect.x;
		int yStart = rect.y;
		int width = rect.width;
		int height = rect.height;

		for (int y = yStart; y < yStart + height; ++y) {
			for (int x = xStart; x < xStart + width; ++x) {
				pBuffer[y * bitmapContent->getwidth() + x] = 0x00000000;
			}
		}
	}

	void eBitmap::EDrawText(eRect rect, eString text, Align align, eRGBA color, int alpha) {
		eImage txtimg(rect.width, rect.height);
		SetWorkingImage(&txtimg);
		settextcolor(RGB(color.R, color.G, color.B));
		settextstyle(eFont::GetFont());
		setbkmode(TRANSPARENT);

		RECT r = { 0, 0, rect.width, rect.height };
		UINT uFormat = DT_WORDBREAK;

		switch (align) {
		case Align::Left:
			uFormat |= DT_LEFT;
			break;
		case Align::Center:
			uFormat |= DT_CENTER;
			break;
		case Align::Right:
			uFormat |= DT_RIGHT;
			break;
		}

		drawtext(text.CString(), &r, uFormat);
		SetWorkingImage(nullptr);

		BYTE R, G, B;
		DWORD* pBuffer = GetImageBuffer(&txtimg);
		for (int i = rect.width * rect.height - 1; i >= 0; --i) {
			R = GetRValue(pBuffer[i]);
			G = GetGValue(pBuffer[i]);
			B = GetBValue(pBuffer[i]);
			int A = (R == 0 && G == 0 && B == 0) ? 0 : 255;
			pBuffer[i] = A << 24 | RGB(R, G, B);
		}
		eImage::Render(bitmapContent, rect.x, rect.y, &txtimg, alpha);
	}

	int eBitmap::TextWidth(eString text) {
		return textwidth(text.CString());
	}

	int eBitmap::TextHeight(eString text) {
		return textheight(text.CString());
	}

	void eBitmap::Save(eString path) {
		saveimage(path.CString(), bitmapContent);
	}

	void eBitmap::FillRect(eImage* img, eRect rect, eRGBA color) {
		DWORD* pBuffer = GetImageBuffer(img);

		if (!img) {
			std::cerr << "Error: img is null!" << std::endl;
			return;
		}

		if (!pBuffer) {
			std::cerr << "Error: Failed to get image buffer!" << std::endl;
			return;
		}

		int xStart = rect.x;
		int yStart = rect.y;
		int width = rect.width;
		int height = rect.height;

		DWORD argbColor = (color.A << 24) | (color.R << 16) | (color.G << 8) | color.B;

		for (int y = yStart; y < yStart + height; ++y) {
			for (int x = xStart; x < xStart + width; ++x) {
				pBuffer[y * img->getwidth() + x] = argbColor;
			}
		}
	}

	void eBitmap::GradientFillRect(eImage* img, eRect rect, eRGBA color1, eRGBA color2, bool isVertical) {
		DWORD* pBuffer = GetImageBuffer(img);

		if (!img) {
			std::cerr << "Error: img is null!" << std::endl;
			return;
		}

		if (!pBuffer) {
			std::cerr << "Error: Failed to get image buffer!" << std::endl;
			return;
		}

		int xStart = rect.x;
		int yStart = rect.y;
		int width = rect.width;
		int height = rect.height;

		for (int y = yStart; y < yStart + height; ++y) {
			for (int x = xStart; x < xStart + width; ++x) {
				float t = 0.0f;
				if (isVertical) {
					t = (float)(y - yStart) / (float)(height);
				}
				else {
					t = (float)(x - xStart) / (float)(width);
				}

				int r = (int)(color1.R + (color2.R - color1.R) * t);
				int g = (int)(color1.G + (color2.G - color1.G) * t);
				int b = (int)(color1.B + (color2.B - color1.B) * t);
				int a = (int)(color1.A + (color2.A - color1.A) * t);

				DWORD argbColor = (a << 24) | (r << 16) | (g << 8) | b;

				pBuffer[y * img->getwidth() + x] = argbColor;
			}
		}
	}
}