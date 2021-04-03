#include <gtest/gtest.h>
#include <stdexcept>

#include "../Fraction.h"
#include "../Fraction.cpp"

TEST(RepeatingLastDigits, ItWorks) {
	auto result = hspc::repeatingLastDigits("125125");
	ASSERT_EQ(result.first, 3);
	ASSERT_EQ(result.second, 0);
}
