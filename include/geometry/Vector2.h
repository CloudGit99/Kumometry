#pragma once


namespace geometry {
	struct Vector2 {
		double x;
		double y;
	};

	double dot(const Vector2& a, const Vector2& b);

	double veclen(const Vector2& a);

	double angleDeg(double lena, double lenb, double sclr);

	Vector2 add(const Vector2& a, const Vector2& b);

	Vector2 subtruct(const Vector2& a, const Vector2& b);

	Vector2 scale(const Vector2& a, double k);
}