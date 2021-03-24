#ifndef FRACX_H
#define FRACX_H

#include <algorithm>
#include <cstdlib>
#include <stdexcept>

namespace hspc {
	using std::__gcd;

	class Fraction {
		typedef long long ll;
		ll _num, _den;
		int _sign;

	public:
		Fraction(ll numerator, ll denominator);

		ll numerator() { return _sign * _num; }
		ll denominator() { return _den; }

		void numerator(ll numerator);
		void denominator(ll denominator);

		Fraction operator-() const;
		Fraction operator+(const Fraction &f);
		Fraction operator-(const Fraction &f);
		Fraction operator*(const Fraction &f);
		Fraction operator/(const Fraction &f);
	};

	inline Fraction::Fraction(ll numerator, ll denominator) {
		if (denominator == 0) {
			throw std::invalid_argument("Denominator couldn't be zero");
		}

		ll gcd = __gcd(llabs(numerator), llabs(denominator));
		_num = llabs(numerator) / gcd;
		_den = llabs(denominator) / gcd;
		_sign = (numerator > 0) != (denominator > 0) ? -1 : 1;
	};

	inline void Fraction::numerator(ll numerator) {
		ll gcd = __gcd(llabs(numerator), _den);
		_num = llabs(numerator) / gcd;
		_den = _den / gcd;
		_sign = (numerator > 0) != (_den > 0) ? -1 : 1;
	}

	inline void Fraction::denominator(ll denominator) {
		if (denominator == 0) {
			throw std::invalid_argument("Denominator couldn't be zero");
		}

		ll gcd = __gcd(_num, llabs(denominator));
		_num = _num / gcd;
		_den = llabs(denominator) / gcd;
		_sign = (_num > 0) != (denominator > 0) ? -1 : 1;
	}

	inline Fraction Fraction::operator-() const {
		return Fraction(-1 * _sign * _num, _den);
	}

	inline Fraction Fraction::operator+(const Fraction &f) {
		ll lcm = (_den * f._den) / __gcd(_den, f._den);

		ll firstNum = (_sign * _num) * (lcm / _den);
		ll secondNum = (f._sign * f._num) * (lcm / f._den);
		return Fraction(firstNum + secondNum, lcm);
	}

	inline Fraction Fraction::operator-(const Fraction &f) {
		return *this + (-f);
	}

	inline Fraction Fraction::operator*(const Fraction &f) {
		return Fraction(_sign * f._sign * _num * f._num, _den * f._den);
	}

	inline Fraction Fraction::operator/(const Fraction &f) {
		return Fraction(_sign * f._sign * _num * f._den, _den * f._num);
	}
}  // namespace hspc

#endif
