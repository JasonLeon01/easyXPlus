#pragma once

#include <easyx.h>
#include <easyXPlus/Base/eString.h>

namespace easyXPlus {
	class eFont {
	public:
		static void Init(eString fontName, int fontHeight = 22);
		static LOGFONT* GetFont();
		static void SetFont(LOGFONT* font);
		static void SetFontHeight(int height);
		static void SetFontWidth(int width);
		static void SetFontWeight(int weight);
		static void SetFontItalic(bool italic);
		static void SetFontUnderline(bool underline);
		static void SetFontStrikeOut(bool strikeOut);
		static void SetFontFaceName(const eString faceName);
		static void SetFontCharSet(BYTE charSet);
		static void SetFontOutPrecision(BYTE outPrecision);
		static void SetFontClipPrecision(BYTE clipPrecision);
		static void SetFontQuality(BYTE quality);
		static void SetFontPitchAndFamily(BYTE pitchAndFamily);

	private:
		static LOGFONT Font;

		eFont() = default;
	};
}