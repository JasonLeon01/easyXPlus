#pragma once
#include <easyXPlus/Base/eString.h>
#include <easyXPlus/Base/eDict.h>
#include <easyXPlus/Base/eRGBA.h>
#include <easyXPlus/Render/eSprite.h>

namespace easyXPlus {
	class Graphics {
	public:
		static void Init(eString title, int inWidth, int inHeight, float inScale = 1.0);
		static void Exit();
		static int GetWidth();
		static int GetHeight();
		static float GetScale();
		static HWND GetHandle();
		static void AddSprite(eSprite* sprite);
		static void RemoveSprite(eSprite* sprite);
		static void Wait(int frames);
		static void Freeze();
		static void Transition(int duration = 10);
		static eBitmap* SnapToBitmap();
		static int GetFrameRate();
		static void SetFrameRate(int rate);
		static void Update();

	private:
		static int width;
		static int height;
		static float scale;
		static HWND handle;
		static eDict <eViewport*, eList<eSprite*>> renderMap;
		static int frameRate;
		static int frameCount;
		static eSprite* frozenGraphic;
	};
}