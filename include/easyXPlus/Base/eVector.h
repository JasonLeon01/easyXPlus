#pragma once

namespace easyXPlus {
	class eVector2d {
	public:
		int x, y;
		eVector2d(int x, int y) : x(x), y(y) {}
		eVector2d() : x(0), y(0) {}
		eVector2d operator+(const eVector2d& other) const;
		eVector2d operator-(const eVector2d& other) const;
		eVector2d operator*(const eVector2d& other) const;
		eVector2d& operator+=(const eVector2d& other);
		eVector2d& operator-=(const eVector2d& other);
		eVector2d& operator*=(const eVector2d& other);
		const bool operator==(const eVector2d& other) const;
		const bool operator!=(const eVector2d& other) const;
	};

	class eVector3d {
	public:
		int x, y, z;
		eVector3d(int x, int y, int z) : x(x), y(y), z(z) {}
		eVector3d() : x(0), y(0), z(0) {}
		eVector3d operator+(const eVector3d& other) const;
		eVector3d operator-(const eVector3d& other) const;
		eVector3d operator*(const eVector3d& other) const;
		eVector3d& operator+=(const eVector3d& other);
		eVector3d& operator-=(const eVector3d& other);
		eVector3d& operator*=(const eVector3d& other);
		const bool operator==(const eVector3d& other) const;
		const bool operator!=(const eVector3d& other) const;
	};

	class eVector2f {
	public:
		float x, y;
		eVector2f(float x, float y) : x(x), y(y) {}
		eVector2f() : x(0), y(0) {}
		eVector2f operator+(const eVector2f& other) const;
		eVector2f operator-(const eVector2f& other) const;
		eVector2f operator*(const eVector2f& other) const;
		eVector2f& operator+=(const eVector2f& other);
		eVector2f& operator-=(const eVector2f& other);
		eVector2f& operator*=(const eVector2f& other);
		const bool operator==(const eVector2f& other) const;
		const bool operator!=(const eVector2f& other) const;
	};

	class eVector3f {
	public:
		float x, y, z;
		eVector3f(float x, float y, float z) : x(x), y(y), z(z) {}
		eVector3f() : x(0), y(0), z(0) {}
		eVector3f operator+(const eVector3f& other) const;
		eVector3f operator-(const eVector3f& other) const;
		eVector3f operator*(const eVector3f& other) const;
		eVector3f& operator+=(const eVector3f& other);
		eVector3f& operator-=(const eVector3f& other);
		eVector3f& operator*=(const eVector3f& other);
		const bool operator==(const eVector3f& other) const;
		const bool operator!=(const eVector3f& other) const;
	};
}