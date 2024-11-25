#pragma once
#include <easyXPlus/Render/eBitmap.h>
#include <easyXPlus/Base/eVector.h>

namespace easyXPlus {
	class eSprite {
	public:
		eBitmap* bitmap;
		// viewport
		eVector3d position;
		eVector2f scale;
		float rotation;
		eVector2d origin;
		bool mirror;
		int hue;

		eSprite();
		eSprite(eBitmap* bitmap);
		eSprite(eBitmap* bitmap, eVector3d position, eVector2f scale = eVector2f(1.f, 1.f), float rotation = 0.f, eVector2d origin = eVector2d(0, 0), bool mirror = false, int hue = 0);

		void Update();
	};
};