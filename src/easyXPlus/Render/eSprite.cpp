#include <easyXPlus/Render/eSprite.h>

namespace easyXPlus {
	eSprite::eSprite(eViewport* inViewport) {
		bitmap = nullptr;
		viewport = inViewport;
		position = { 0, 0, 0 };
		rotation = 0.f;
		opacity = 255;
		origin = { 0, 0 };
	}

	eSprite::eSprite(eBitmap* inBitmap, eViewport* inViewport) {
		bitmap = inBitmap;
		viewport = inViewport;
		position = { 0, 0, 0 };
		rotation = 0.f;
		opacity = 255;
		origin = { 0, 0 };
	}

	eSprite::eSprite(eBitmap* inBitmap, eVector3d inPosition, eViewport* inViewport, float inRotation, BYTE inOpacity, eVector2d inOrigin) {
		bitmap = inBitmap;
		position = inPosition;
		viewport = inViewport;
		rotation = inRotation;
		opacity = inOpacity;
		origin = inOrigin;
	}

	eViewport* eSprite::GetViewport() {
		return viewport;
	}

	void eSprite::Update() {
		if (bitmap) {
			eImage* dstimg = bitmap->GetImage();
			if (static_cast<int>(rotation) % 360 != 0) {
				dstimg = nullptr;
				rotateimage(dstimg, bitmap->GetImage(), rotation, 0UL, true);
			}
			eImage::Render(viewport, position.x + origin.x, position.y + origin.y, bitmap->GetImage(), opacity);
		}
	}
}