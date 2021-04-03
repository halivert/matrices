#include <gtest/gtest.h>
#include <stdexcept>

#include "../Fraction.h"

using hspc::Fraction;

TEST(BaseFraction, ItMustCreateAFractionWith1) {
	Fraction f(1);
	ASSERT_EQ(f.numerator(), 1);
	ASSERT_EQ(f.denominator(), 1);
}

TEST(BaseFraction, ThrowErrorWhenDenominatorIsZero) {
	ASSERT_THROW(Fraction f(1, 0), std::invalid_argument);
}

TEST(BasicFractionOperations, FractionsCanBeAdded) {
	Fraction f(1, 2), g(2, 4);

	ASSERT_EQ(f + g, Fraction(1));
}

TEST(BasicFractionOperations, FractionsCanBeSubtracted) {
	Fraction f(1, 2), g(2, 4);

	ASSERT_EQ(f - g, Fraction(0));
}

TEST(BasicFractionOperations, FractionsCanBeMultiplied) {
	Fraction f(1, 2), g(2, 4);

	ASSERT_EQ(f * g, Fraction(2, 8));
}

TEST(BasicFractionOperations, FractionsCanBeDivided) {
	Fraction f(1, 2), g(2, 4);

	ASSERT_EQ(f / g, Fraction(1));
}
