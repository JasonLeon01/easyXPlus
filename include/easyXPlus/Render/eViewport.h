#pragma once
#include <easyXPlus/Render/eImage.h>
#include <easyXPlus/Base/eVector.h>
#include <easyXPlus/Base/eRGBA.h>

namespace easyXPlus {
	class eViewport : public eImage {
	public:
		eVector3d position;
		int ox, oy;

		static eViewport* DefaultViewport;

		eViewport(eRect rect, int _z = 0);

		const bool operator < (const eViewport& other) const {
			return position.z < other.position.z;
		}

		void Flash(eRGBA color, int duration);
		void Update();

	private:
		int flashCount;
		int flashDuration;
		eRGBA flashColor;

		eViewport() = default;
	};
}