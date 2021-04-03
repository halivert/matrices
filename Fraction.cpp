#ifndef FRACC_H
#define FRACC_H

#include "Fraction.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

namespace hspc {
	using std::__gcd;
	const double ERROR = 1e-9;
	inline bool Zero(double a, double error = ERROR) { return fabs(a) < error; }
	typedef unsigned int ui;

	std::pair<ui, ui> repeatingLastDigits(std::string stringNum) {
		long long stringNumSize = stringNum.length();

		for (size_t i = 1; i <= stringNumSize >> 1; ++i) {
			for (size_t j = 0; j < stringNumSize - i; ++j) {
				bool valid = true;
				for (size_t k = 1; k < ceil((stringNumSize - j) * 1.0 / i); ++k) {
					std::string sub = stringNum.substr(j + (i * k), i);
					std::string check = stringNum.substr(j, std::min(i, sub.length()));

					valid &= !check.compare(sub);
					if (!valid) break;
				}
				if (valid) return {i, j};
			}
		}

		return {1, stringNumSize - 1};
	}

	Fraction::Fraction(double d) {
		if (fabs(d) == 1 / 0.0) {
			throw std::invalid_argument("Denominator couldn't be zero");
		}

		std::string numStr = std::to_string(d);

		ll i = numStr.find(".") + 1;

		ll integer = std::stoll(numStr.substr(0, i - 1));
		std::string decimals = numStr.substr(i);

		ll numZeros = decimals.length();

		ll den = pow(10, numZeros);
		ll num = d * den;

		if (std::stoll(decimals) > 0) {
			auto repeating = repeatingLastDigits(decimals);
			std::string preSub = decimals.substr(0, repeating.second);
			std::string periodicSub = decimals.substr(repeating.second);

			ll pre = preSub.length() ? std::stoll(preSub) : 0;
			ll periodic = std::stoll(periodicSub);

			std::string nines = std::string(periodicSub.length(), '9');
			std::string zeros = std::string(preSub.length(), '0');

			den = std::stoll(nines + zeros);
			num = (integer * den) +
						std::stoll(
								decimals.substr(0, periodicSub.length() + preSub.length())) -
						pre;
		}

		ll gcd = __gcd(num, den);

		if (gcd == 1) {
			ll tmp;
			if ((tmp = __gcd(num - 1, den)) != 1) {
				gcd = tmp;
				num--;
			}
		}

		_den = den / gcd;
		_num = num / gcd;
		_sign = d < 0 ? -1 : 1;
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
