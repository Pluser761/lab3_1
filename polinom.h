#pragma once
#include <iostream>

using namespace std;

template<typename T> class polynom
{
private:
	int size;
	T* p;
	friend istream& operator>>(istream&, const polynom&);
	friend ostream& operator<<(ostream&, const polynom&);
public:
	polynom();
	polynom(int);
	~polynom();

	polynom operator+(const polynom&);
	polynom operator-(const polynom&);
	polynom operator*(const polynom&);
	polynom operator/(const polynom&);
};

template<typename T> polynom<T>::polynom()
{
	size = 0;
	p = 0;
}

template<typename T> polynom<T>::polynom(int n)
{
	size = n;
	for (int i = 0; i < size; i++) p[i] = 0;
}

template<typename T> polynom<T>::~polynom()
{

}

template<typename T> polynom<T> polynom<T>::operator+(const polynom &st)
{
	T* ret;
	if (size <= st.size)
	{
		ret = st;
		for (int i = 0; i < size; i++)
		{
			ret[i] = ret[i] + p[i];
		}
	}
	else
	{
		ret = this;
		for (int i = 0; i < st.size; i++)
		{
			ret[i] = ret[i] + st.p[i];
		}
	}
	return ret;
}

template<typename T> polynom<T> polynom<T>::operator-(const polynom &st)
{
	T* ret;
	if (size <= st.size)
	{
		ret = st;
		for (int i = 0; i < size; i++) ret[i] = ret[i] - p[i];
	}
	else
	{
		ret = this;
		for (int i = 0; i < st.size; i++) ret[i] = ret[i] - st.p[i];
	}
	return ret;
}

template<typename T> polynom<T> polynom<T>::operator*(const polynom &st)
{
	T* ret(size + st.size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < st.size; j++)
			ret[i + j] = ret[i + j] + p[i] * st.p[j];

	return ret;
}

template<typename T> polynom<T> polynom<T>::operator/(const polynom &st)
{

}

template<typename T> istream& operator>>(istream &in, polynom<T> &st)
{
	in.
	return in;
}

template<typename T> ostream& operator>>(ostream &out, const polynom<T> &st)
{
	if (st.size == 0) return out;
	out << st.p[0];
	for (int i = 1; i < st.size; i++)
		out << st.p[i];
	return out;
}