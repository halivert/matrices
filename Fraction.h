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
		Fraction(ll = 0, ll = 1);
		Fraction(double);

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

		inline bool operator<(const Fraction &f) {
			return (_num * f._den) < (_den * f._num);
		}

		inline bool operator==(const Fraction &f) {
			return (_num * f._den) == (_den * f._num);
		}

		inline bool operator!=(const Fraction &f) { return !(*this == f); }
		inline bool operator>(const Fraction &f) { return *this < f; }
		inline bool operator<=(const Fraction &f) { return !(*this > f); }
		inline bool operator>=(const Fraction &f) { return !(*this < f); }
	};

	std::ostream &operator<<(std::ostream &, const Fraction &);
}  // namespace hspc

#endif
