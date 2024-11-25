#include <easyXPlus/Render/eSprite.h>

namespace easyXPlus {
	eSprite::eSprite() : bitmap(nullptr), position(0, 0, 0), scale(1.f, 1.f), rotation(0.f), origin(0, 0), mirror(false), hue(0) {}

	eSprite::eSprite(eBitmap* bitmap) : bitmap(bitmap), position(), scale(1.f, 1.f), rotation(0.f), origin(0, 0), mirror(false), hue(0) {}

	eSprite::eSprite(eBitmap* bitmap, eVector3d position, eVector2f scale, float rotation, eVector2d origin, bool mirror, int hue) : bitmap(bitmap), position(position), scale(scale), rotation(rotation), origin(origin), mirror(mirror), hue(hue) {}

	void eSprite::Update() {
		eRenderUtils::Render(nullptr, position.x, position.y, bitmap->GetImage());
	}
}