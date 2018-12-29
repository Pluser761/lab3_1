//#include "fraction.h"
//#include <iostream>
//																	//шаблоны не работают с fraction.cpp
//using namespace std;
//
//template <typename T> fraction<T>::fraction(T n, T d)
//{
//	this->numerator = n;
//	this->denominator = d;
//}
//
//template <typename T> fraction<T>::~fraction()
//{
//}
//
//template <typename T> fraction<T> fraction<T>::operator+(fraction &st)
//{
//	if (denominator == st.denominator) return fraction(numerator + st.numerator, denominator);
//	else return fraction(numerator*st.denominator + st.numerator*denominator, denominator*st.denominator);
//}
//
//template <typename T> fraction<T> fraction<T>::operator-(fraction &st)
//{
//	if (denominator == st.denominator) return fraction(numerator - st.numerator, denominator);
//	else return fraction(numerator*st.denominator - st.numerator*denominator, denominator*st.denominator);
//}
//
//template <typename T> fraction<T> fraction<T>::operator*(fraction &st)
//{
//	return fraction(numerator*st.numerator, denominator*st.denominator);
//}
//
//template <typename T> fraction<T> fraction<T>::operator/(fraction &st)
//{
//	return fraction(numerator*st.denominator, denominator*st.numerator);
//}
//
//template <typename T> ostream& operator<<(ostream &out, const fraction<T> &st)
//{
//	out << st.numerator << "/" << st.denominator << "\n";
//	return out;
//}
//
//template <typename T> void fraction<T>::printClass()
//{
//	printf("%d/%d\n", numerator, denominator);
//}
//
