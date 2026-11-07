#include <gtest/gtest.h>
#include "geometry/Vector2.h"

TEST(GeometryTest, BasicSclr) {
	geometry::Vector2 a;
	geometry::Vector2 b;
	a.x = 1;
	a.y = 2;
	b.x = 3;
	b.y = 4;
	EXPECT_DOUBLE_EQ(11.0, dot(a, b));
}

TEST(GeometryTest, BasicLength) {
	geometry::Vector2 a;
	a.x = 3;
	a.y = 4;
	EXPECT_DOUBLE_EQ(5.0, veclen(a));
}

TEST(GeometryTest, BasicSumm) {
	geometry::Vector2 a;
	geometry::Vector2 b;
	geometry::Vector2 result;
	a.x = 1;
	a.y = 2;
	b.x = 3;
	b.y = 4;
	result = add(a, b);
	EXPECT_DOUBLE_EQ(4.0, result.x);
	EXPECT_DOUBLE_EQ(6.0, result.y);
}

TEST(GeometryTest, BasicSubtruct) {
	geometry::Vector2 a;
	geometry::Vector2 b;
	geometry::Vector2 result;
	a.x = 1;
	a.y = 2;
	b.x = 3;
	b.y = 4;
	result = subtruct(a, b);
	EXPECT_DOUBLE_EQ(-2.0, result.x);
	EXPECT_DOUBLE_EQ(-2.0, result.y);
}

TEST(GeometryTest, BasicScaler) {
	geometry::Vector2 a;
	geometry::Vector2 result;
	double k;
	a.x = 1;
	a.y = 2;
	k = 2.5;
	result = scale(a, k);
	EXPECT_DOUBLE_EQ(2.5, result.x);
	EXPECT_DOUBLE_EQ(5.0, result.y);
}

TEST(GeometryTest, ZeroScaler) {
	geometry::Vector2 a;
	geometry::Vector2 result;
	double k;
	a.x = 1;
	a.y = 2;
	k = 0;
	result = scale(a, k);
	EXPECT_DOUBLE_EQ(0.0, result.x);
	EXPECT_DOUBLE_EQ(0.0, result.y);
}

TEST(GeometryTest, NegativeScaler) {
	geometry::Vector2 a;
	geometry::Vector2 result;
	double k;
	a.x = 3;
	a.y = 4;
	k = -1;
	result = scale(a, k);
	EXPECT_DOUBLE_EQ(5.0, veclen(a));
	EXPECT_DOUBLE_EQ(-3.0, result.x);
	EXPECT_DOUBLE_EQ(-4.0, result.y);
	EXPECT_DOUBLE_EQ(5.0, veclen(result));
}