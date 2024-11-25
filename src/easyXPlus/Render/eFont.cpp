#include <easyXPlus/Render/eFont.h>

namespace easyXPlus {
	LOGFONT eFont::Font;

	void eFont::Init(eString fontName, int fontHeight) {
		SetFontFaceName(fontName);
		SetFontHeight(fontHeight);
		SetFontQuality(ANTIALIASED_QUALITY);
	}

	LOGFONT* eFont::GetFont() {
		return &Font;
	}

	void eFont::SetFont(LOGFONT* font) {
		Font = *font;
	}

	void eFont::SetFontHeight(int height) {
		Font.lfHeight = height;
	}

	void eFont::SetFontWidth(int width) {
		Font.lfWidth = width;
	}

	void eFont::SetFontWeight(int weight) {
		Font.lfWeight = weight;
	}

	void eFont::SetFontItalic(bool italic) {
		Font.lfItalic = italic;
	}

	void eFont::SetFontUnderline(bool underline) {
		Font.lfUnderline = underline;
	}

	void eFont::SetFontStrikeOut(bool strikeOut) {
		Font.lfStrikeOut = strikeOut;
	}

	void eFont::SetFontFaceName(const eString faceName) {
		_tcsncpy(Font.lfFaceName, faceName.CString(), LF_FACESIZE);
	}

	void eFont::SetFontCharSet(BYTE charSet) {
		Font.lfCharSet = charSet;
	}

	void eFont::SetFontOutPrecision(BYTE outPrecision) {
		Font.lfOutPrecision = outPrecision;
	}

	void eFont::SetFontClipPrecision(BYTE clipPrecision) {
		Font.lfClipPrecision = clipPrecision;
	}

	void eFont::SetFontQuality(BYTE quality) {
		Font.lfQuality = quality;
	}

	void eFont::SetFontPitchAndFamily(BYTE pitchAndFamily) {
		Font.lfPitchAndFamily = pitchAndFamily;
	}
}