#pragma once
#include <iostream>
#include <vector>

using namespace std;

template<typename T> class matrix
{
private:
	vector<vector<T>> data;
	friend ostream& operator<<(ostream &stream, const matrix<T> &mat)
	{
		for (int i = 0; i < mat.data.size(); i++)
		{
			for (int j = 0; j < mat.data.size(); j++)
				stream << mat.data[i][j];
			stream << "\n";
		}
		return stream;
	}
public:
	matrix();
	matrix(vector<vector<T>> data);
	~matrix();

	matrix<T> tran();
	matrix<T> inverse();
	matrix<T> adding(int, int);
	friend T deter(const matrix<T> &mat);

	matrix operator+(const matrix &);
	matrix operator-(const matrix &);
	matrix operator*(const matrix &);
	matrix operator*(const T &);
	matrix operator/(const matrix &);
	matrix operator=(const matrix &);
};

template<typename T>
inline matrix<T>::matrix()
{
}

template<typename T>
inline matrix<T>::matrix(vector<vector<T>> data)
{
	this->data = data;
}

template<typename T>
inline matrix<T>::~matrix()
{
}

template<typename T>
inline matrix<T> matrix<T>::tran()
{
	matrix<T> ret(data);
	for (int i = 1; i < ret.data.size(); i++) for (int j = 1; j < ret.data.size(); j++) swap(ret.data[i][j], ret.data[j][i]);
	return ret;
}

template<typename T>
inline matrix<T> matrix<T>::inverse()
{
	return matrix<T>();
}

template<typename T>
inline matrix<T> matrix<T>::adding(int i, int j)
{
	vector<vector<T>> res(data.size() - 1);
	for (int r = 0; r < data.size() - 1; r++) res[r].resize(data.size() - 1);
	int c_i = 0, c_j;

	for (int b = 0; b < data.size(); b++)
	{
		if (b == i) continue;
		c_j = 0;
		for (int c = 0; c < data.size(); c++)
		{
			if (c == j) continue;
			res[c_i][c_j] = data[b][c];
			c_j++;
		}
		c_i++;
	}
		
	return matrix<data.size() - 1, T>(res);
}

template<typename T> T deter(const matrix<T> &mat)
{
	if (mat.data.size() == 1)
		return mat.data[0][0];
	else
	{
		T ret = deter(mat.adding(0, 0));
		for (int i = 1; i < (int)mat.data.size(); i++)
			ret = ret + deter(mat.adding(0, i)) * (pow(-1, i));
		return ret;
	}
}

template<typename T> matrix<T> matrix<T>::operator+(const matrix &st)
{
	vector<vector<T>> ret;
	for (int i = 0; i < data.size(); i++)
		for (int j = 0; j < data.size(); j++)
			ret[i][j] = data[i][j] + st.data[i][j];
	return matrix<T>(ret);
}

template<typename T> matrix<T> matrix<T>::operator-(const matrix &)
{
	return matrix();
}

template<typename T> matrix<T> matrix<T>::operator*(const matrix &)
{
	return matrix();
}

template<typename T> matrix<T> matrix<T>::operator*(const T &st)
{
	for (int i = 0; i < data.size(); i++)
		for (int j = 0; j < data.size(); j++)
			data[i][j] = data[i][j] * st;
	return *this;
}

template<typename T> matrix<T> matrix<T>::operator/(const matrix &)
{
	return matrix();
}

template<typename T> matrix<T> matrix<T>::operator=(const matrix &st)
{
	data = st.data;
	return *this;
}
