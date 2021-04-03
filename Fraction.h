#ifndef FRACH_H
#define FRACH_H

#include <algorithm>
#include <cstdlib>
#include <ostream>
#include <stdexcept>

namespace hspc {
	class Fraction {
		typedef long long ll;
		ll _num, _den;
		int _sign;

	public:
		template <class T>
		Fraction(T numerator, T denominator = 1) {
			if (denominator == 0) {
				throw std::invalid_argument("Denominator couldn't be zero");
			}

			ll gcd = std::__gcd(llabs(numerator), llabs(denominator));
			_num = llabs(numerator) / gcd;
			_den = llabs(denominator) / gcd;
			_sign = (numerator > 0) != (denominator > 0) ? -1 : 1;
		};

		inline ll numerator() { return _sign * _num; }
		inline ll denominator() { return _den; }
		inline ll numerator() const { return _sign * _num; };
		inline ll denominator() const { return _den; }

		void numerator(ll);
		void denominator(ll);

		Fraction operator-() const;
		Fraction operator+(const Fraction &);
		Fraction operator-(const Fraction &);
		Fraction operator*(const Fraction &);
		Fraction operator/(const Fraction &);

		inline Fraction &operator+=(const Fraction &f) { return *this = *this + f; }
		inline Fraction &operator-=(const Fraction &f) { return *this = *this - f; }
		inline Fraction &operator*=(const Fraction &f) { return *this = *this * f; }
		inline Fraction &operator/=(const Fraction &f) { return *this = *this / f; }

		inline bool operator<(const Fraction &f) {
			return (_num * f._den) < (_den * f._num);
		}

		inline bool operator==(const Fraction &f) const {
			return (_num * f._den) == (_den * f._num);
		}

		inline bool operator!=(const Fraction &f) { return !(*this == f); }
		inline bool operator>(const Fraction &f) { return *this < f; }
		inline bool operator<=(const Fraction &f) { return !(*this > f); }
		inline bool operator>=(const Fraction &f) { return !(*this < f); }

		inline double to_d() const { return 1.0 * _sign * _num / _den; }
	};

	std::ostream &operator<<(std::ostream &, const Fraction &);
}  // namespace hspc

#endif
