#include <easyXPlus/Base/eVector.h>

namespace easyXPlus {
	eVector2d eVector2d::operator+(const eVector2d& other) const {
		return eVector2d(x + other.x, y + other.y);
	}

	eVector2d eVector2d::operator-(const eVector2d& other) const {
		return eVector2d(x - other.x, y - other.y);
	}

	eVector2d eVector2d::operator*(const eVector2d& other) const {
		return eVector2d(x * other.x, y * other.y);
	}

	eVector2d& eVector2d::operator+=(const eVector2d& other) {
		x += other.x;
		y += other.y;
		return *this;
	}

	eVector2d& eVector2d::operator-=(const eVector2d& other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	eVector2d& eVector2d::operator*=(const eVector2d& other) {
		x *= other.x;
		y *= other.y;
		return *this;
	}

	const bool eVector2d::operator==(const eVector2d& other) const {
		return x == other.x && y == other.y;
	}

	const bool eVector2d::operator!=(const eVector2d& other) const {
		return x != other.x || y != other.y;
	}

	eVector3d eVector3d::operator+(const eVector3d& other) const {
		return eVector3d(x + other.x, y + other.y, z + other.z);
	}

	eVector3d eVector3d::operator-(const eVector3d& other) const {
		return eVector3d(x - other.x, y - other.y, z - other.z);
	}

	eVector3d eVector3d::operator*(const eVector3d& other) const {
		return eVector3d(x * other.x, y * other.y, z * other.z);
	}

	eVector3d& eVector3d::operator+=(const eVector3d& other) {
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	eVector3d& eVector3d::operator-=(const eVector3d& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	eVector3d& eVector3d::operator*=(const eVector3d& other) {
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}

	const bool eVector3d::operator==(const eVector3d& other) const {
		return x == other.x && y == other.y && z == other.z;
	}

	const bool eVector3d::operator!=(const eVector3d& other) const {
		return x != other.x || y != other.y || z != other.z;
	}

	eVector2f eVector2f::operator+(const eVector2f& other) const {
		return eVector2f(x + other.x, y + other.y);
	}

	eVector2f eVector2f::operator-(const eVector2f& other) const {
		return eVector2f(x - other.x, y - other.y);
	}

	eVector2f eVector2f::operator*(const eVector2f& other) const {
		return eVector2f(x * other.x, y * other.y);
	}

	eVector2f& eVector2f::operator+=(const eVector2f& other) {
		x += other.x;
		y += other.y;
		return *this;
	}

	eVector2f& eVector2f::operator-=(const eVector2f& other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	eVector2f& eVector2f::operator*=(const eVector2f& other) {
		x *= other.x;
		y *= other.y;
		return *this;
	}

	const bool eVector2f::operator==(const eVector2f& other) const {
		return x == other.x && y == other.y;
	}

	const bool eVector2f::operator!=(const eVector2f& other) const {
		return x != other.x || y != other.y;
	}

	eVector3f eVector3f::operator+(const eVector3f& other) const {
		return eVector3f(x + other.x, y + other.y, z + other.z);
	}

	eVector3f eVector3f::operator-(const eVector3f& other) const {
		return eVector3f(x - other.x, y - other.y, z - other.z);
	}

	eVector3f eVector3f::operator*(const eVector3f& other) const {
		return eVector3f(x * other.x, y * other.y, z * other.z);
	}

	eVector3f& eVector3f::operator+=(const eVector3f& other) {
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	eVector3f& eVector3f::operator-=(const eVector3f& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	eVector3f& eVector3f::operator*=(const eVector3f& other) {
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}

	const bool eVector3f::operator==(const eVector3f& other) const {
		return x == other.x && y == other.y && z == other.z;
	}

	const bool eVector3f::operator!=(const eVector3f& other) const {
		return x != other.x || y != other.y || z != other.z;
	}
}