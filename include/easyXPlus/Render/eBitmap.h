#pragma once
#include <easyx.h>
#include <easyXPlus/Base/eString.h>
#include <easyXPlus/Base/eRect.h>
#include <easyXPlus/Base/eVector.h>
#include <easyXPlus/Base/eRGBA.h>
#include <easyXPlus/Render/eImage.h>

namespace easyXPlus {
	enum Align {
		Left,
		Center,
		Right
	};

	class eBitmap {
	public:
		eBitmap(int width, int height);
		eBitmap(eImage* src);
		~eBitmap();

		int GetWidth();
		int GetHeight();
		eImage* GetImage();
		void Blit(int x, int y, eBitmap* srcBitmap, eRect srcRect, int opacity = 0);
		void FillRect(eRect rect, eRGBA color);
		void GradientFillRect(eRect rect, eRGBA color1, eRGBA color2, bool isVertical = true);
		void Clear();
		void ClearRect(eRect rect);
		void EDrawText(eRect rect, eString text, Align align = Align::Left, eRGBA color = eRGBA::White, int alpha = 255);
		int TextWidth(eString text);
		int TextHeight(eString text);
		void Save(eString path);

		static void FillRect(eImage* img, eRect rect, eRGBA color);
		static void GradientFillRect(eImage* img, eRect rect, eRGBA color1, eRGBA color2, bool isVertical = true);

	private:
		eImage* bitmapContent;
		eBitmap() = default;
	};
}
