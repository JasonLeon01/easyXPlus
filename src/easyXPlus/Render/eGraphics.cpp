#include <easyXPlus/Render/eGraphics.h>
#include <chrono>
#include <thread>

namespace easyXPlus {
	int Graphics::width = 640;
	int Graphics::height = 480;
	float Graphics::scale = 1.0f;
	eDict <eViewport*, eList<eSprite*>> Graphics::renderMap;
	int Graphics::frameRate = 60;
	int Graphics::frameCount = 0;
	eSprite* Graphics::frozenGraphic = nullptr;

	void Graphics::Init(eString title, int inWidth, int inHeight, float inScale) {
		scale = inScale;
		width = inWidth * scale;
		height = inHeight * scale;
		setaspectratio(scale, scale);
		handle = initgraph(width, height);
		setbkmode(TRANSPARENT);
		setbkcolor(TRANSPARENT);
		setlinecolor(WHITE);
		setfillcolor(WHITE);
		setbkcolor(BLUE);
		setbkmode(TRANSPARENT);
		setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 1);
		SetWindowText(handle, title.CString());
		BeginBatchDraw();
	}

	void Graphics::Exit() {
		EndBatchDraw();
		closegraph();
	}

	int Graphics::GetWidth() {
		return width;
	}

	int Graphics::GetHeight() {
		return height;
	}

	float Graphics::GetScale() {
		return scale;
	}

	HWND Graphics::GetHandle() {
		return handle;
	}

	void Graphics::AddSprite(eSprite* sprite) {
		if (renderMap.ContainsKey(sprite->GetViewport())) {
			renderMap[sprite->GetViewport()].Append(sprite);
		}
		else {
			eList<eSprite*> list;
			list.Append(sprite);
			renderMap.Add(sprite->GetViewport(), list);
		}
	}

	void Graphics::RemoveSprite(eSprite* sprite) {
		if (renderMap.ContainsKey(sprite->GetViewport())) {
			renderMap[sprite->GetViewport()].Remove(sprite);
			if (renderMap[sprite->GetViewport()].Size() == 0) {
				renderMap.Remove(sprite->GetViewport());
			}
		}
	}

	void Graphics::Wait(int frames) {
		for (int i = 0; i < frames; i++) {
			Graphics::Update();
		}
	}

	void Graphics::Freeze() {
		if (!frozenGraphic) {
			eImage* frozen = new eImage(GetWidth(), GetHeight());
			getimage(frozen, 0, 0, GetWidth(), GetHeight());
			frozenGraphic = new eSprite(new eBitmap(frozen), nullptr);
		}
	}

	void Graphics::Transition(int duration) {
		if (frozenGraphic) {
			for (int i = 0; i < duration; i++) {
				frozenGraphic->opacity = 255 - i * 255 / duration;
				Graphics::Update();
			}
			delete frozenGraphic;
			frozenGraphic = nullptr;
		}
	}

	eBitmap* Graphics::SnapToBitmap() {
		eImage* image = new eImage(GetWidth(), GetHeight());
		getimage(image, 0, 0, GetWidth(), GetHeight());
		eBitmap* bitmap = new eBitmap(image);
		return bitmap;
	}

	int Graphics::GetFrameRate() {
		return frameRate;
	}

	void Graphics::SetFrameRate(int rate) {
		frameRate = rate;
	}

	void Graphics::Update() {
		float frameDuration = 1.0f / frameRate;
		auto startTime = std::chrono::high_resolution_clock::now();
		cleardevice();
		if (frozenGraphic) {
			frozenGraphic->Update();
		}
		else {
			eList <eViewport*> viewportList = renderMap.GetKeys().SortedList();
			for (int i = 0; i < viewportList.Size(); i++) {
				viewportList[i]->Clear(eRGBA::Transparent);
				eList <eSprite*> spriteList = renderMap[viewportList[i]].SortedList();
				for (int j = 0; j < spriteList.Size(); j++) {
					spriteList[j]->Update();
				}
				viewportList[i]->Update();
			}
		}
		FlushBatchDraw();
		++frameCount;
		auto endTime = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> elapsed = endTime - startTime;
		float elapsedSeconds = elapsed.count();
		float waitTime = frameDuration - elapsedSeconds;
		if (waitTime > 0) {
			std::this_thread::sleep_for(std::chrono::duration<float>(waitTime));
		}
	}
}