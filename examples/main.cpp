#include <iostream>
#include <iomanip>
#include "geometry/Vector2.h"

int main() {
	int menu;
	double sclr, lena, lenb, lenc, Angle, scaler;
	geometry::Vector2 a;
	geometry::Vector2 b;
	geometry::Vector2 c;
	do {
		std::cout << "Hello Geometry!\n";
		std::cout << "Please, type x of vector a: ";
		std::cin >> a.x;
		std::cout << "Please, type y of vector a: ";
		std::cin >> a.y;
		std::cout << "Please, type x of vector b: ";
		std::cin >> b.x;
		std::cout << "Please, type y of vector b: ";
		std::cin >> b.y;
		std::cout << "Please, type scaler: ";
		std::cin >> scaler;
		sclr = geometry::dot(a, b);
		std::cout << "Scalar: " << sclr << "\n";
		lena = geometry::veclen(a);
		std::cout << "Length a: " << lena << "\n";
		lenb = geometry::veclen(b);
		std::cout << "Length b: " << lenb << "\n";
		if ((a.x == 0 && a.y == 0) || (b.x == 0 && b.y == 0)) {
			std::cout << "\nUndefined angle\n";
		}
		else {
			if (sclr < 0) {
				std::cout << "\nMore then 90 angle\n";
			}
			else if (sclr > 0) {
				std::cout << "\nLess then 90 angle\n";
			}
			else if (sclr == 0) {
				std::cout << "\n90 angle\n";
			}
			Angle = geometry::angleDeg(lena, lenb, sclr);
			std::cout << "Angle: " << std::setprecision(4) << std::fixed << Angle << " degrees\n";
		}
		c = geometry::add(a, b);
		std::cout << std::defaultfloat << "After summation: \n" << c.x << ", " << c.y << "\n";
		c = geometry::subtruct(a, b);
		std::cout << "After substruction: \n" << c.x << ", " << c.y << "\n";
		c = geometry::scale(a, scaler);
		std::cout << "Vector 'a' after scaling: \n" << c.x << ", " << c.y << "\n";
		lenc = geometry::veclen(c);
		std::cout << "Length 'a' after scaling: " << lenc << "\n";
		c = geometry::scale(b, scaler);
		std::cout << "Vector 'b' after scaling: \n" << c.x << ", " << c.y << "\n";
		lenc = geometry::veclen(c);
		std::cout << "Length 'b' after scaling: " << lenc << "\n";
		std::cout << "Whats next?\n>1)CONTINUE\n>0)END\n>>";
		std::cin >> menu;
	} while (menu == 1);

    return 0;
}