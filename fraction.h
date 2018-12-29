#pragma once
#include <iostream>

using namespace std;

template<typename T> class fraction
{
private:
	T numerator;
	T denominator;
public:
	fraction(T n = 0, T d = 1);
	~fraction();

	fraction operator+(const fraction);
	fraction operator-(const fraction);
	fraction operator*(const fraction);
	fraction operator*(const T);
	fraction operator/(const fraction);
	fraction& operator=(const fraction&);

	bool operator>=(const T);
	bool operator<(const T);

	friend ostream& operator<<(ostream &, const fraction<T> &);
	friend fraction<T> pow<T>(fraction<T>, int);
};

template<typename T> fraction<T>::fraction(T n = 0, T d = 1)
{
	if (!d) throw("Denum is zero")
	else
	{
		denominator = d;
		numerator = n;
	}
}

template<typename T> fraction<T>::~fraction()
{
}

template<typename T> fraction<T> fraction<T>::operator+(const fraction &st)
{
	if (denominator == st.denominator) return fraction(numerator + st.numerator, denominator);
	else return fraction(numerator*st.denominator + st.numerator*denominator, denominator*st.denominator);
}

template<typename T> fraction<T> fraction<T>::operator-(const fraction &st)
{
	if (denominator == st.denominator) return fraction(numerator - st.numerator, denominator);
	else return fraction(numerator*st.denominator - st.numerator*denominator, denominator*st.denominator);
}

template<typename T> fraction<T> fraction<T>::operator*(const fraction &st)
{
	return fraction(numerator*st.numerator, denominator*st.denominator);
}

template<typename T> fraction<T> fraction<T>::operator/(const fraction &st)
{
	return fraction(numerator*st.denominator, denominator*st.numerator);
}

template<typename T> fraction<T>& fraction<T>::operator=(const fraction &st)
{
	numerator = st->numerator;
	denominator = st->denominator;
	return *this;
}

template<typename T> fraction<T>::operator double()
{
	if (denominator == 0) return 0;
	return (numerator / denominator);
}

template<typename T> ostream& operator<<(ostream &out, const fraction<T> &st)
{
	out << "[" << st.numerator << "/" << st.denominator << "]";
	return out;
}

template<typename T> istream& operator>>(istream &in, fraction<T> &fr)
{
	in >> fr.numerator >> fr.denominator;
	return in;
}
