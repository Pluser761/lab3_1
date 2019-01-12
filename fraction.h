#pragma once
#include <iostream>

using namespace std;

template<typename T> class fraction
{
private:
	T numerator;
	T denominator;
	friend ostream& operator<<(ostream &out, const fraction<T> &st)
	{
		out << "[" << st.numerator << "/" << st.denominator << "]";
		return out;
	}
public:
	fraction();
	fraction(T, T);
	~fraction();

	fraction operator+(const fraction&);
	fraction operator-(const fraction&);
	fraction operator*(const fraction&);
	//fraction operator*(const T);
	fraction operator/(const fraction&);
	fraction operator=(const fraction&);
};

template<typename T> fraction<T>::fraction()
{
	numerator = 0;
	denominator = 1;
}

template<typename T> fraction<T>::fraction(T n, T d)
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

template<typename T>
inline fraction<T> fraction<T>::operator+(const fraction &st)
{
	if (denominator == st.denominator) return fraction(numerator + st.numerator, denominator);
	else return fraction(numerator*st.denominator + st.numerator*denominator, denominator*st.denominator);
}

template<typename T>
inline fraction<T> fraction<T>::operator-(const fraction &st)
{
	if (denominator == st.denominator) return fraction(numerator - st.numerator, denominator);
	else return fraction(numerator*st.denominator - st.numerator*denominator, denominator*st.denominator);
}

template<typename T>
inline fraction<T> fraction<T>::operator*(const fraction &st)
{
	return fraction(numerator*st.numerator, denominator*st.denominator);
}

template<typename T>
inline fraction<T> fraction<T>::operator/(const fraction &st)
{
	return fraction(numerator*st.denominator, denominator*st.numerator);
}

template<typename T>
inline fraction<T>	fraction<T>::operator=(const fraction &st)
{
	numerator = st->numerator;
	denominator = st->denominator;
	return *this;
}