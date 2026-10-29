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

double angle(double lena, double lenb, double sclr) {
	double a, cosAngle;
	cosAngle = (sclr / (lena * lenb));
	if (cosAngle > 1)
		cosAngle = 1;
	if (cosAngle < -1)
		cosAngle = -1;
	a = acos(cosAngle) * 180 /pi; //использована pi из numbers
	return a;
}

Vector2 add(const Vector2& a, const Vector2& b) {
	Vector2 c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return  c;
}

int main() {
	int menu;
	double sclr, lena, lenb, Angle;
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
			Angle = angle(lena, lenb, sclr);
			cout << "Angle: " << setprecision(4) << fixed << Angle << " degrees\n";
		}
		c = add(a, b);
		cout << defaultfloat << "New vector c: \n" << c.x << ", " << c.y << "\n";
		cout << "Whats next?\n>1)CONTINUE\n>0)END\n>>";
		cin >> menu;
	} while (menu == 1);
	
}