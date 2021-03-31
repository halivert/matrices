#include <gtest/gtest.h>

#include "../Fraction.h"

using hspc::Fraction;

TEST(Fraction, ItMustCreateAFractionWith1) {
	Fraction f(1);
	ASSERT_EQ(f.numerator(), 1);
	ASSERT_EQ(f.denominator(), 1);
}

TEST(Fraction, FractionsCanBeAdded) {
	Fraction f(1, 2), g(2, 4);

	ASSERT_EQ(f + g, Fraction(1));
}

TEST(Fraction, FractionsCanBeSubtracted) {
	Fraction f(1, 2), g(2, 4);

	ASSERT_EQ(f - g, Fraction(0));
}

TEST(Fraction, FractionsCanBeMultiplied) {
	Fraction f(1, 2), g(2, 4);

	ASSERT_EQ(f * g, Fraction(2, 8));
}

TEST(Fraction, FractionsCanBeDivided) {
	Fraction f(1, 2), g(2, 4);

	ASSERT_EQ(f / g, Fraction(1));
}
