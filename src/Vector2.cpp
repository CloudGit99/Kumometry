#include "geometry/Vector2.h"
#include <cmath>
#include <numbers>

namespace geometry {

	double dot(const Vector2& a, const Vector2& b) {
		double sclr;
		sclr = a.x * b.x + a.y * b.y;
		return sclr;
	}

	double veclen(const Vector2& a) {
		double len;
		len = std::sqrt(a.x * a.x + a.y * a.y);
		return len;
	}

	double angleDeg(double lena, double lenb, double sclr) {
		double angle, cosAngle;
		cosAngle = (sclr / (lena * lenb));
		if (cosAngle > 1)
			cosAngle = 1;
		if (cosAngle < -1)
			cosAngle = -1;
		angle = std::acos(cosAngle) * 180 / std::numbers::pi; //использована pi из numbers
		return angle;
	}

	Vector2 add(const Vector2& a, const Vector2& b) {
		Vector2 c;
		c.x = a.x + b.x;
		c.y = a.y + b.y;
		return  c;
	}

	Vector2 subtruct(const Vector2& a, const Vector2& b) {
		Vector2 c;
		c.x = a.x - b.x;
		c.y = a.y - b.y;
		return c;
	}

	Vector2 scale(const Vector2& a, double k) {
		Vector2 c;
		c.x = k * a.x;
		c.y = k * a.y;
		return c;
	}
}