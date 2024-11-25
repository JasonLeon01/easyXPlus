# easyXPlus 

`easyXPlus` 是基于 `easyX` 进行封装的一个图形和渲染库，旨在为 C++ 开发者提供一个更易于使用的接口，来处理图形、位图、矩形、颜色、字体等基本图形操作。该项目封装了许多常用的图形绘制、文本渲染、图像处理等功能，可以被用于图形应用和游戏开发。

# **正在编写中，尚未完成，目前只有最基本的渲染**

## 目录结构

- `Base/`
  - `ePair.h`: 封装键值对（key-value pair）数据结构的模板类。
  - `eRect.h`: 提供用于定义矩形区域的类。
  - `eRGBA.h`: 封装 RGBA 颜色的类，支持颜色操作。
  - `eString.h`: 提供了字符串的封装类，支持常见的字符串操作，如连接、查找、替换等。
  - `eVector.h`: 提供二维和三维向量的类，支持常见的向量操作。
- `Render/`
  - `eRenderUtils.h`: 提供渲染工具类，支持图像渲染操作。
  - `eSprite.h`: 提供精灵（Sprite）类，支持图像、位置、缩放、旋转等操作。
  - `eBitmap.h`: 提供位图（Bitmap）操作类，支持加载、绘制、清除、保存等图像操作。
  - `eFont.h`: 提供字体操作类，支持设置和获取字体属性。

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
- 成员函数：返回矩形的 `x`、`y`、`width` 和 `height`。

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

### `eVector2d` 和 `eVector3d`
这两个类分别代表二维和三维向量。它们支持常见的向量操作，如加法、减法、乘法等。

### `eVector2f` 和 `eVector3f`
这两个类是 `eVector2d` 和 `eVector3d` 的浮点数版本，支持更精细的数值计算。

### `eBitmap`
`eBitmap` 类提供了图像处理功能，支持以下操作：
- 加载和获取图像宽高。
- 绘制图像、填充矩形、渐变填充等功能。
- 渲染文本和图像到目标区域。
- 保存图像到指定路径。

### `eFont`
`eFont` 类用于设置和管理字体，支持字体名称、大小、粗细、样式等属性的设置。

### `eRenderUtils`
`eRenderUtils` 提供了静态渲染方法，用于将图像渲染到指定位置。

### `eSprite`
`eSprite` 类表示一个精灵对象，包含一个 `eBitmap` 作为图像，并提供位置、缩放、旋转等变换操作。

## 示例代码

### 创建和显示一个简单的文本

```cpp
#include <easyXPlus/Render/eBitmap.h>
#include <easyXPlus/Base/eString.h>
#include <easyXPlus/Render/eRenderUtils.h>
#include <easyXPlus/eFont.h>

int main() {
    // 初始化窗口
    auto hwnd = initgraph(640, 480);

    // 初始化字体
    easyXPlus::eFont::Init(_T("Arial"), 30);

    // 创建一个位图
    easyXPlus::eBitmap bitmap(500, 500);

    // 绘制文本
    bitmap.EDrawText(easyXPlus::eRect(100, 100, 300, 50), _T("Hello, easyXPlus!"));

    // 渲染到屏幕
    easyXPlus::eRenderUtils::Render(nullptr, 0, 0, bitmap.GetImage());
    
    // 保持窗口显示
    _getch();

    // 关闭窗口
    closegraph();
    
    return 0;
}
```

### 创建并操作精灵

```cpp
#include <easyXPlus/Render/eSprite.h>

int main() {
    // 初始化窗口
    auto hwnd = initgraph(640, 480);
  
    // 创建一个位图
    easyXPlus::eBitmap bitmap(200, 200);
    
    // 创建一个精灵
    easyXPlus::eSprite sprite(&bitmap);
    sprite.position = easyXPlus::eVector3d(100, 100, 0);
    
    // 执行精灵的更新，并渲染到屏幕上
    sprite.Update();
    
    // 保持窗口显示
    _getch();

    // 关闭窗口
    closegraph();

    return 0;
}
```
