#pragma once
#include <iostream>
#include <map>

using namespace std;

template<typename T> class polynom
{
private:
	map<int, T> data;
	friend ostream& operator<<(ostream &out, const polynom &st)
	{
		for (int i = st.data.size() - 1; i <= 0; i--)
			out << st.data[i] << "x^" << i << " _ ";
		return out;
	}
public:
	polynom();
	polynom(vector<T>);
	~polynom();

	polynom operator+(const polynom&);
	polynom operator-(const polynom&);
	polynom operator*(const polynom&);
	polynom operator/(const polynom&);
};

template<typename T> polynom<T>::polynom()
{
}

template<typename T> polynom<T>::polynom(vector<T> vec)
{
	data = vec;
}

template<typename T> polynom<T>::~polynom()
{

}

template<typename T> polynom<T> polynom<T>::operator+(const polynom &st)
{
	if (size != st.size)
	{
		cout << "Polynoms have different length.\n";
		exit(-1);
	}
	else
	{
		vector<T> ret = data;
		for (int i = 0; i < data.size(); i++)
			ret[i] = ret[i] + st.data[i];
	}
	return polynom<T>(ret);
}

template<typename T> polynom<T> polynom<T>::operator-(const polynom &st)
{
	if (size != st.size)
	{
		cout << "Polynoms have different length.\n";
		exit(-1);
	}
	else
	{
		vector<T> ret = data;
		for (int i = 0; i < data.size(); i++)
			ret[i] = ret[i] - st.data[i];
	}
	return polynom<T>(ret);
}

template<typename T> polynom<T> polynom<T>::operator*(const polynom &st)
{
	vector<T> ret(data.size()*st.data.size());
	for (int i = 0; i < size; i++)
		for (int j = 0; j < st.size; j++)
			ret[i + j] = ret[i + j] + p[i] * st.p[j];

	return ret;
}

template<typename T> polynom<T> polynom<T>::operator/(const polynom &st)
{

}