#ifndef FRACC_H
#define FRACC_H

#include "Fraction.h"

#include <algorithm>
#include <cmath>
#include <iostream>

namespace hspc {
	using std::__gcd;
	const double ERROR = 1e-9;
	inline bool Zero(double a, double error = ERROR) { return fabs(a) < error; }

	long long gcd(long long a, long long b) {
		if (b == 0) return a;
		a %= b;
		return gcd(b, a);
	}

	Fraction::Fraction(double d) {
		if (fabs(d) == 1 / 0.0) {
			throw std::invalid_argument("Denominator couldn't be zero");
		}

		double cD = d;

		ll denominator = 1, repeating, lastDig;
		/* while (cD != std::floor(cD) and k--) { */
		repeating = 0, lastDig = 0;
		/* for (denominator = 1; denominator < 1e9; denominator *= 10) { */
		while (cD != std::floor(cD) and denominator < 10e6) {
			cD *= 10.0;
			denominator *= 10;

			repeating += (ll)cD % 10 == lastDig ? 1 : -repeating;
			lastDig = ((ll)cD % 10);
		}

		ll gcd = __gcd(llabs((ll)cD), llabs(denominator));
		_num = llabs((ll)cD) / gcd;
		_den = denominator / gcd;
		_sign = (d < 0) ? -1 : 1;
	};

	void Fraction::numerator(ll numerator) {
		ll gcd = __gcd(llabs(numerator), _den);
		_num = llabs(numerator) / gcd;
		_den = _den / gcd;
		_sign = (numerator > 0) != (_den > 0) ? -1 : 1;
	}

	void Fraction::denominator(ll denominator) {
		if (denominator == 0) {
			throw std::invalid_argument("Denominator couldn't be zero");
		}

		ll gcd = __gcd(_num, llabs(denominator));
		_num = _num / gcd;
		_den = llabs(denominator) / gcd;
		_sign = (_num > 0) != (denominator > 0) ? -1 : 1;
	}

	Fraction Fraction::operator-() const {
		return Fraction(-1 * _sign * _num, _den);
	}

	Fraction Fraction::operator+(const Fraction &f) {
		ll lcm = (_den * f._den) / __gcd(_den, f._den);

		ll firstNum = (_sign * _num) * (lcm / _den);
		ll secondNum = (f._sign * f._num) * (lcm / f._den);
		return Fraction(firstNum + secondNum, lcm);
	}

	Fraction Fraction::operator-(const Fraction &f) { return *this + (-f); }

	Fraction Fraction::operator*(const Fraction &f) {
		return Fraction(_sign * f._sign * _num * f._num, _den * f._den);
	}

	Fraction Fraction::operator/(const Fraction &f) {
		return Fraction(_sign * f._sign * _num * f._den, _den * f._num);
	}

	std::ostream &operator<<(std::ostream &os, const Fraction &f) {
		os << f.numerator() << '/' << f.denominator();
		return os;
	}
}  // namespace hspc

#endif /* ifndef FRACC_H */
