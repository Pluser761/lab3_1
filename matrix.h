#pragma once
#include <iostream>
#include <vector>

using namespace std;

template<int S, typename T> class matrix
{
private:
	vector<vector<T>> data;
	friend ostream& operator<<(ostream &stream, const matrix<S, T> &mat)
	{
		for (int i = 0; i < S; i++)
		{
			for (int j = 0; j < S; j++)
				stream << mat.data[i][j];
			stream << "\n";
		}
		return stream;
	}
public:
	matrix();
	matrix(vector<vector<T>> data);
	~matrix();

	matrix<S, T> tran();
	matrix<S, T> inverse();
	matrix<S - 1, T> adding(int i, int j);
	T deter(T);

	matrix operator+(const matrix &);
	matrix operator-(const matrix &);
	matrix operator*(const matrix &);
	matrix operator*(const T &);
	matrix operator/(const matrix &);
	matrix operator=(const matrix &);
};

template<int S, typename T>
inline matrix<S, T>::matrix()
{
}

template<int S, typename T>
inline matrix<S, T>::matrix(vector<vector<T>> data)
{
	this->data = data;
}

template<int S, typename T>
inline matrix<S, T>::~matrix()
{
}

template<int S, typename T>
inline matrix<S, T> matrix<S, T>::tran()
{
	matrix<S, T> ret(data);
	for (int i = 1; i < ret.data.size(); i++) for (int j = 1; j < ret.data.size(); j++) swap(ret.data[i][j], ret.data[j][i]);
	return ret;
}

template<int S, typename T>
inline matrix<S, T> matrix<S, T>::inverse()
{

	return matrix<S, T>();
}

template<int S, typename T>
inline matrix<S - 1, T> matrix<S, T>::adding(int i, int j)
{
	vector<vector<T>> res(S - 1);
	for (int r = 0; r < S - 1; r++) res[r].resize(S - 1);
	int c_i = 0, c_j;

	for (int b = 0; b < S; b++)
	{
		if (b == i) continue;
		c_j = 0;
		for (int c = 0; c < S; c++)
		{
			if (c == j) continue;
			res[c_i][c_j] = data[b][c];
			c_j++;
		}
		c_i++;
	}
		
	return matrix<S - 1, T>(res);
}

template<int S, typename T>
T matrix<S, T>::deter(T nul)
{
	if (S == 1)
		return data[0][0];
	else
	{
		T ret = nul;
		for (int i = 0; i < (int)data.size(); i++)
			ret = ret + adding(0, i).deter(nul) * (pow(-1, i));
		return ret;
	}
}

template<int S, typename T> matrix<S, T> matrix<S, T>::operator+(const matrix &st)
{
	vector<vector<T>> ret;
	for (int i = 0; i < S; i++)
		for (int j = 0; j < S; j++)
			ret[i][j] = data[i][j] + st.data[i][j];
	return matrix<S, T>(ret);
}

template<int S, typename T> matrix<S, T> matrix<S, T>::operator-(const matrix &)
{
	return matrix();
}

template<int S, typename T> matrix<S, T> matrix<S, T>::operator*(const matrix &)
{
	return matrix();
}

template<int S, typename T>
inline matrix<S, T> matrix<S, T>::operator*(const T &st)
{
	for (int i = 0; i < S; i++)
		for (int j = 0; j < S; j++)
			data[i][j] = data[i][j] * st;
	return *this;
}

template<int S, typename T> matrix<S, T> matrix<S, T>::operator/(const matrix &)
{
	return matrix();
}

template<int S, typename T> matrix<S, T> matrix<S, T>::operator=(const matrix &st)
{
	data = st.data;
	return *this;
}
