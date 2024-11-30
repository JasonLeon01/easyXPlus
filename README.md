# easyXPlus 

`easyXPlus` 是基于 `easyX` 进行封装的一个图形和渲染库，旨在为 C++ 开发者提供一个更易于使用的接口，来处理图形、位图、矩形、颜色、字体等基本图形操作。该项目封装了许多常用的图形绘制、文本渲染、图像处理等功能，可以被用于图形应用和游戏开发。

# **正在编写中，尚未完成，目前只有最基本的渲染**

# 前注

需使用最新的easyX，虽然还没出。

easyX作者称需要2025年元旦前后才有时间。

## 目录结构

- `Base/`
  - `ePair.h`: 封装键值对（key-value pair）数据结构的模板类。
  - `eRect.h`: 提供用于定义矩形区域的类。
  - `eRGBA.h`: 封装 RGBA 颜色的类，支持颜色操作。
  - `eString.h`: 提供了字符串的封装类，支持常见的字符串操作，如连接、查找、替换等。
  - `eList.h` : 提供了列表的封装类，支持常见的列表操作，如增加、删除、查找等。
  - `eDict.h` : 提供了字典的封装类，严格遵循插入顺序，查找效率相对较低，支持常见的字典操作，支持下标查找键。
  - `eVector.h`: 提供二维和三维向量的类，支持常见的向量操作。
- `Render/`
  - `eImage.h` : 对 `easyx.h` 中 `IMAGE` 类型的扩展，提供了图像清空、渲染等功能。
  - `eViewport.h` : 继承自 `eImage`，用于表示视口的渲染区域，支持位置控制、闪烁效果以及视口更新等功能。
  - `eBitmap.h`: 用于处理位图图像的类，提供了一些常用的图像操作方法，例如位图的绘制、填充、文本绘制等。
  - `eSprite.h`: 表示一个精灵对象，它可以具有位置、旋转、透明度等属性。它可以与 `eViewport` 结合使用来渲染精灵图像，支持位图操作和各种变换效果。
  - `eFont.h`: 提供字体操作类，支持设置和获取字体属性。
  - `eGraphics.h` : 用于处理图形的初始化、更新和渲染管理。它提供了各种静态方法来控制图形窗口、分辨率、帧率等，并且可以管理多个 `eSprite` 对象的渲染。`Graphics` 类在图形应用中充当了中央控制器，负责界面的初始化、更新和资源管理。

## 依赖

- `easyx`: 用于图形绘制的第三方库，作为渲染的基础工具。
- `C++17` 或更高版本的编译器。

## 安装

1. 将 `easyXPlus` 源代码包含到你的 C++ 项目中。
2. 确保你已经安装并配置好 `easyx` 库。
3. 编译项目时，确保链接到 `easyx` 库。

## 类和功能说明

### `ePair<T1, T2>`
`ePair` 是一个模板类，用于存储一对键值对。它包含以下成员函数：
- 构造函数：支持默认构造和自定义构造。
- 运算符重载：支持相等比较 `==` 和不相等比较 `!=`。

### `eRect`
`eRect` 类用于定义矩形区域，包含以下功能：
- 构造函数：支持通过坐标和尺寸初始化。

### `eRGBA`
`eRGBA` 类封装 RGBA 颜色，包含以下成员：
- 构造函数：支持自定义颜色值。
- 运算符重载：支持颜色比较。
- `ToColorRef()`：将颜色转换为 `COLORREF` 格式。

### `eString`
`eString` 类封装了字符串，提供了多种字符串操作：
- 常见的字符串运算符：如 `==`、`+` 等。
- 支持查找、替换、分割、转换大小写等功能。
- 支持格式化字符串。

### `eList`
`eList` 是一个封装了动态数组操作的容器类，支持基本的插入、删除、查找、排序等功能。它具有类似于标准库中 `std::vector` 的功能，但提供了一些额外的操作，如插入、删除指定值以及排序等。
- `Append(const T& value)`：将元素添加到列表末尾。
- `Insert(size_t index, const T& value)`：在指定位置插入元素。
- `RemoveAt(size_t index)`：删除指定位置的元素。
- `Remove(const T& value)`：删除第一个匹配的元素。
- `RemoveAll(const T& value)`：删除所有匹配的元素。
- `Find(const T& value)`：查找元素，返回其索引，未找到则返回 -1。
- `Pop()`：弹出并返回列表末尾的元素。
- `Sort()`：对列表中的元素进行排序。
- `SortedList()`：返回一个排序后的新列表，原列表不变。
- `Clear()`：清空列表。
- `Size()`：返回当前列表的大小。
- `Empty()`：检查列表是否为空。

### `eDict`
`eDict` 是一个基于链表实现的字典（哈希表）类，支持键值对的插入、删除、查找等操作。它支持通过键访问值，并提供了迭代器以便遍历字典中的键值对。
- `Add(TKey key, TValue value)`：将一个键值对添加到字典中。
- `Size()`：返回字典中键值对的数量。
- `Clear()`：清空字典，删除所有节点。
- `KeyAt(size_t index)`：根据索引返回键。
- `ValueAt(size_t index)`：根据索引返回值。
- `ContainsKey(TKey key)`：检查字典中是否包含指定的键。
- `GetKeys()`：返回字典中所有键的列表 `eList<TKey>`。

### `eVector2d` 和 `eVector3d`
这两个类分别代表二维和三维向量。它们支持常见的向量操作，如加法、减法、乘法等。

### `eVector2f` 和 `eVector3f`
这两个类是 `eVector2d` 和 `eVector3d` 的浮点数版本，支持更精细的数值计算。

### `eImage`
`eImage` 类是对 `easyx.h` 中 `IMAGE` 类型的扩展，提供了图像清空、渲染等功能。
- `eImage(int _width = 0, int _height = 0)`：构造函数，初始化图像对象，可以指定图像的宽度和高度。
- `Clear(eRGBA color)`：使用指定的颜色填充整个图像，常用于清空图像或设置背景色。
- `static void Render(IMAGE* dstimg, int x, int y, IMAGE* srcimg, BYTE opacity = 255)`：将源图像 `srcimg` 渲染到目标图像 `dstimg` 上，渲染位置由 `(x, y)` 确定，`opacity` 参数用于控制透明度，默认为不透明。
- `static void Render(IMAGE* dstimg, int x, int y, IMAGE* srcimg, eRect cropRect, BYTE opacity = 255)`：将源图像 `srcimg` 的指定区域 `cropRect` 渲染到目标图像 `dstimg` 上，渲染位置由 `(x, y)` 确定，`opacity` 参数用于控制透明度，默认为不透明。

### `eViewport`
`eViewport` 类继承自 `eImage`，用于表示视口的渲染区域，支持位置控制、闪烁效果以及视口更新等功能。
- `eViewport(eRect rect, int _z = 0)`：构造函数，初始化视口对象。通过 `rect` 参数指定视口的区域（即宽度和高度），`_z` 参数设置视口的深度值，默认深度为 `0`。`z` 值用于排序视口，较小的 `z` 值会被优先渲染。
- `Flash(eRGBA color, int duration)`：使视口闪烁，`color` 参数指定闪烁的颜色，`duration` 参数指定闪烁持续的时间。可以用于实现过渡效果或特殊的视觉效果。
- `void Update()`：更新视口的状态，通常用于处理视口位置变化、效果更新等。
- `eVector3d position`：一个 3D 向量，表示视口的位置（`x`，`y`，`z`），`z` 值用于确定视口在渲染中的层次。
- `int ox, oy`：视口的原点坐标，用于定位视口在渲染区域中的位置。
- `static eViewport* DefaultViewport`：默认视口，通常用于场景的主视图或全局视口。

### `eBitmap`
`eBitmap` 是一个用于处理位图图像的类，提供了一些常用的图像操作方法，例如位图的绘制、填充、文本绘制等。
- `eBitmap(int width, int height)`：根据指定的宽度和高度创建一个新的空白位图。
- `eBitmap(eImage* src)`：使用指定的 `eImage` 对象初始化一个位图。
- `GetWidth()`：返回位图的宽度。
- `GetHeight()`：返回位图的高度。
- `GetImage()`：返回 `eImage` 对象指针，可以用于进一步的图像操作。
- `Blit(int x, int y, eBitmap* srcBitmap, eRect srcRect, int opacity = 0)`：将源位图 `srcBitmap` 中的指定区域 `srcRect` 绘制到当前位图的指定位置 `(x, y)`，支持透明度设置。
- `FillRect(eRect rect, eRGBA color)`：使用指定的颜色填充矩形区域。
- `GradientFillRect(eRect rect, eRGBA color1, eRGBA color2, bool isVertical = true)`：使用渐变色填充矩形区域，支持纵向或横向渐变。
- `Clear()`：清空当前位图内容。
- `ClearRect(eRect rect)`：清空指定的矩形区域。
- `EDrawText(eRect rect, eString text, Align align = Align::Left, eRGBA color = eRGBA::White, int alpha = 255)`：在指定矩形区域内绘制文本，支持文本对齐、颜色和透明度设置。
- `TextWidth(eString text)`：返回指定文本的宽度。
- `TextHeight(eString text)`：返回指定文本的高度。
- `Save(eString path)`：将位图保存到指定路径。
- `static void FillRect(eImage* img, eRect rect, eRGBA color)`：使用指定的颜色填充 `eImage` 对象的矩形区域。
- `static void GradientFillRect(eImage* img, eRect rect, eRGBA color1, eRGBA color2, bool isVertical = true)`：使用渐变色填充 `eImage` 对象的矩形区域，支持纵向或横向渐变。

### `eSprite`
- `eSprite(eViewport* inViewport = eViewport::DefaultViewport)`：构造函数，创建一个默认视口的精灵对象。视口可以指定渲染的目标区域，默认为 `DefaultViewport`。
- `eSprite(eBitmap* inBitmap, eViewport* inViewport = eViewport::DefaultViewport)`：构造函数，指定精灵的纹理（位图），同时设置渲染的视口。默认视口为 `DefaultViewport`。
- `(eBitmap* inBitmap, eVector3d inPosition, eViewport* inViewport = eViewport::DefaultViewport, float inRotation = 0.f, BYTE inOpacity = 255, eVector2d inOrigin = eVector2d(0, 0))`：该构造函数允许更精细地控制精灵的所有属性。
- `GetViewport()`：获取精灵所在的视口。
- `Update()`：更新精灵的状态。通常用于更新精灵的位置、旋转、透明度等属性，可能用于动画或动态效果。
- `eBitmap* bitmap`：精灵的位图对象，定义了精灵的外观。
- `eVector3d position`：精灵的位置，包含 `x`, `y`, `z` 坐标。
- `float rotation`：精灵的旋转角度，以度为单位。
- `BYTE opacity`：精灵的透明度，取值范围是 `0`（完全透明）到 `255`（完全不透明）。
- `eVector2d origin`：精灵的原点，影响旋转和缩放时的参考点。

### `eFont`
`eFont` 类用于处理字体的初始化和设置，通过修改字体的各个属性（如字体名称、高度、粗细等）来调整文本渲染的样式。该类利用 Windows API `LOGFONT` 结构来定义和操作字体样式。
- `static void Init(eString fontName, int fontHeight = 22)`：
  - 初始化字体设置，设置字体名称和高度（默认为 22）。
  - `fontName`：字体名称，如 `"Arial"`、`"Times New Roman"` 等。
  - `fontHeight`：字体高度，默认为 22。
- `static LOGFONT* GetFont()`：
  - 获取当前的字体 `LOGFONT` 结构。
- `static void SetFont(LOGFONT* font)`：
  - 设置自定义的 `LOGFONT` 字体结构。
- `static void SetFontHeight(int height)`：
  - 设置字体高度。
- `static void SetFontWidth(int width)`：
  - 设置字体宽度。
- `static void SetFontWeight(int weight)`：
  - 设置字体的粗细程度，通常取值范围为 `FW_DONTCARE`（不设置）到 `FW_BOLD`（加粗）。
- `static void SetFontItalic(bool italic)`：
  - 设置字体是否为斜体，`true` 为斜体，`false` 为常规字体。
- `static void SetFontUnderline(bool underline)`：
  - 设置字体是否带下划线，`true` 为带下划线，`false` 为无下划线。
- `static void SetFontStrikeOut(bool strikeOut)`：
  - 设置字体是否带删除线，`true` 为带删除线，`false` 为不带。
- `static void SetFontFaceName(const eString faceName)`：
  - 设置字体的面部名称（例如 `"Arial"`、`"Comic Sans MS"`）。
- `static void SetFontCharSet(BYTE charSet)`：
  - 设置字体字符集。常用值为 `ANSI_CHARSET`、`DEFAULT_CHARSET` 等。
- `static void SetFontOutPrecision(BYTE outPrecision)`：
  - 设置字体输出精度。通常使用 `OUT_DEFAULT_PRECIS`、`OUT_TT_PRECIS` 等值。
- `static void SetFontClipPrecision(BYTE clipPrecision)`：
  - 设置字体剪裁精度。常用值包括 `CLIP_DEFAULT_PRECIS`、`CLIP_TT_PRECIS` 等。
- `static void SetFontQuality(BYTE quality)`：
  - 设置字体的质量。常用值包括 `DEFAULT_QUALITY`、`CLEARTYPE_QUALITY` 等。
- `static void SetFontPitchAndFamily(BYTE pitchAndFamily)`：
  - 设置字体的间距和家庭属性。常用值包括 `DEFAULT_PITCH` 和 `FF_SWISS`。

### `eGraphics`
`Graphics` 类用于处理图形的初始化、更新和渲染管理。它提供了各种静态方法来控制图形窗口、分辨率、帧率等，并且可以管理多个 `eSprite` 对象的渲染。`Graphics` 类在图形应用中充当了中央控制器，负责界面的初始化、更新和资源管理。
- `static void Init(eString title, int inWidth, int inHeight, float inScale = 1.0)`：
  - 初始化图形系统，创建图形窗口。
  - `title`：窗口的标题。
  - `inWidth`：窗口的宽度。
  - `inHeight`：窗口的高度。
  - `inScale`：缩放因子（默认值为 `1.0`）。
- `static void Exit()`：
  - 退出图形系统，关闭窗口并清理资源。
- `static int GetWidth()`：
  - 获取图形窗口的宽度。
- `static int GetHeight()`：
  - 获取图形窗口的高度。
- `static float GetScale()`：
  - 获取缩放因子。
- `static HWND GetHandle()`：
  - 获取窗口的句柄（`HWND` 类型），通常用于与操作系统的窗口管理进行交互。
- `static void AddSprite(eSprite* sprite)`：
  - 向渲染队列中添加一个 `eSprite` 对象，进行后续渲染。
- `static void RemoveSprite(eSprite* sprite)`：
  - 从渲染队列中移除一个 `eSprite` 对象。
- `static void Wait(int frames)`：
  - 程序暂停指定的帧数。通常用于动画控制和帧同步。
- `static void Freeze()`：
  - 冻结当前的图形状态，停止更新和渲染。
- `static void Transition(int duration = 10)`：
  - 创建一个过渡效果，通常用于屏幕淡入淡出等效果。
  - `duration`：过渡的持续时间（默认为 10 帧）。
- `static eBitmap* SnapToBitmap()`：
  - 捕捉当前图形内容为一个 `eBitmap` 对象，可以用于后续保存或处理。
- `static int GetFrameRate()`：
  - 获取当前的帧率。
- `static void SetFrameRate(int rate)`：
  - 设置帧率。
- `static void Update()`：
  - 更新图形状态，执行渲染等操作。
- `static int width`：
  - 图形窗口的宽度。
- `static int height`：
  - 图形窗口的高度。
- `static float scale`：
  - 窗口的缩放因子。
- `static HWND handle`：
  - 窗口句柄，用于与操作系统交互。
- `static eDict <eViewport*, eSprite*> renderMap`：
  - 渲染队列，保存视口与精灵的映射关系。
- `static int frameRate`：
  - 当前帧率。
- `static int frameCount`：
  - 当前帧数，用于计数和更新逻辑。
- `static eImage* frozenGraphic`：
  - 当前冻结的图形状态。

## 示例代码

### 创建并操作精灵

```cpp
// 略
```
