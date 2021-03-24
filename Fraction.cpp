#ifndef FRACC_H
#define FRACC_H

#include "Fraction.h"

#include <cmath>

namespace hspc {
	using std::__gcd;
	const double ERROR = 1e-9;
	inline bool Zero(double a) { return fabs(a) < ERROR; }

	Fraction::Fraction(ll numerator, ll denominator) {
		if (denominator == 0) {
			throw std::invalid_argument("Denominator couldn't be zero");
		}

		ll gcd = __gcd(llabs(numerator), llabs(denominator));
		_num = llabs(numerator) / gcd;
		_den = llabs(denominator) / gcd;
		_sign = (numerator > 0) != (denominator > 0) ? -1 : 1;
	};

	Fraction::Fraction(double d){};

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
