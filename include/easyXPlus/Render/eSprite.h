#pragma once
#include <easyXPlus/Render/eBitmap.h>
#include <easyXPlus/Base/eVector.h>
#include <easyXPlus/Render/eViewport.h>

namespace easyXPlus {
	class eSprite {
	public:
		eBitmap* bitmap;
		eVector3d position;
		float rotation;
		BYTE opacity;
		eVector2d origin;

		eSprite(eViewport* inViewport = eViewport::DefaultViewport);
		eSprite(eBitmap* inBitmap, eViewport* inViewport = eViewport::DefaultViewport);
		eSprite(eBitmap* inBitmap, eVector3d inPosition, eViewport* inViewport = eViewport::DefaultViewport, float inRotation = 0.f, BYTE inOpacity = 255, eVector2d inOrigin = eVector2d(0, 0));

		const bool operator < (const eSprite& other) const {
			return position.z < other.position.z;
		}

		eViewport* GetViewport();
		void Update();

	private:
		eViewport* viewport;

		eSprite() = default;
	};
};