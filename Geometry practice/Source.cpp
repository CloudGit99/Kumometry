#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <numbers>
#include <iomanip>

using namespace ::std;
using namespace ::numbers;

struct Vector2 {
	double x;
	double y;
};

double dot(const Vector2 &a, const Vector2 &b) {
	double sclr;
	sclr = a.x * b.x + a.y * b.y;
	return sclr;
}

double veclen(const Vector2 &a) {
	double len;
	len = sqrt(a.x * a.x + a.y * a.y);
	return len;
}

double angleDeg(double lena, double lenb, double sclr) {
	double angle, cosAngle;
	cosAngle = (sclr / (lena * lenb));
	if (cosAngle > 1)
		cosAngle = 1;
	if (cosAngle < -1)
		cosAngle = -1;
	angle = acos(cosAngle) * 180 / pi; //использована pi из numbers
	return angle;
}

Vector2 add(const Vector2& a, const Vector2& b) {
	Vector2 c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return  c;
}

Vector2 substruct(const Vector2& a, const Vector2& b) {
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

int main() {
	int menu;
	double sclr, lena, lenb, lenc, Angle, scaler;
	Vector2 a;
	Vector2 b;
	Vector2 c;
	do {
		cout << "Hello Geometry!\n";
		cout << "Please, type x of vector a: ";
		cin >> a.x;
		cout << "Please, type y of vector a: ";
		cin >> a.y;
		cout << "Please, type x of vector b: ";
		cin >> b.x;
		cout << "Please, type y of vector b: ";
		cin >> b.y;
		cout << "Please, type scaler: ";
		cin >> scaler;
		sclr = dot(a, b);
		cout << "Scalar: " << sclr << "\n";
		lena = veclen(a);
		cout << "Length a: " << lena << "\n";
		lenb = veclen(b);
		cout << "Length b: " << lenb << "\n";
		if ((a.x == 0 && a.y == 0) || (b.x == 0 && b.y == 0)) {
			cout << "\nUndefined angle\n";
		}
		else{
			if (sclr < 0) {
			cout << "\nMore then 90 angle\n";
			}
			else if (sclr > 0) {
			cout << "\nLess then 90 angle\n";
			}
			else if (sclr == 0) {
			cout << "\n90 angle\n";
			}
			Angle = angleDeg(lena, lenb, sclr);
			cout << "Angle: " << setprecision(4) << fixed << Angle << " degrees\n";
		}
		c = add(a, b);
		cout << defaultfloat << "After summation: \n" << c.x << ", " << c.y << "\n";
		c = substruct(a, b);
		cout << "After substruction: \n" << c.x << ", " << c.y << "\n";
		c = scale(a, scaler);
		cout << "Vector 'a' after scaling: \n" << c.x << ", " << c.y << "\n";
		lenc = veclen(c);
		cout << "Length 'a' after scaling: " << lenc << "\n";
		c = scale(b, scaler);
		cout << "Vector 'b' after scaling: \n" << c.x << ", " << c.y << "\n";
		lenc = veclen(c);
		cout << "Length 'b' after scaling: " << lenc << "\n";
		cout << "Whats next?\n>1)CONTINUE\n>0)END\n>>";
		cin >> menu;
	} while (menu == 1);
	
}