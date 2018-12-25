#pragma once
#include <iostream>
#include <vector>

using namespace std;

template<int S, typename T> class matrix
{
private:
	vector<vector<T>> data;
	//friend ostream& operator<<<T>(ostream&, const matrix<T>&);
public:
	matrix();
	matrix(vector<vector<T>> data);
	~matrix();

	matrix<S, T> tran();
	matrix<S, T> reverse();

	matrix operator+(const matrix &);
	matrix operator-(const matrix &);
	matrix operator*(const matrix &);
	//matrix operator/(const matrix &);
	matrix operator=(const matrix &);

	matrix inverse();
};

template<typename T> matrix<T>::matrix(const matrix &st)
{
	n = st.n;
	arr = new T*[n];
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = new T[n];
		for (int j = 0; j < n; j++) *(*(arr + i) + j) = st.arr[i][j];
	}
}

template<typename T> matrix<T>::matrix()
{
	n = 0;
	arr = 0;
}

template<typename T> matrix<T>::matrix(int size)
{
	n = size;
	arr = new T*[n];
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = new T[n];
		for (int j = 0; j < n; j++) *(*(arr + i) + j) = 0;
	}
}

template<typename T> matrix<T>::~matrix()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) delete(*(arr + i));
	delete(arr);
}

template<typename T> matrix<T> matrix<T>::operator+(const matrix &st)
{
	matrix ret(n);
	for (int i = 0; i < st.n; i++)
		for (int j = 0; j < st.n; j++)
			ret.arr[i][j] = arr[i][j] + st.arr[i][j];
	return ret;
}

template<typename T> matrix<T> matrix<T>::operator-(const matrix &st)
{
	matrix ret(n);
	for (int i = 0; i < st.n; i++)
		for (int j = 0; j < st.n; j++)
			ret.arr[i][j] = arr[i][j] - st.arr[i][j];
	return ret;
}

template<typename T> matrix<T> matrix<T>::operator*(const matrix &st)
{
	matrix<T> ret(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			T value = 0;
			for (int k = 0; k < n; k++) value += arr[i][k] * st.arr[k][j];
		}
}

//template <typename T> matrix<T> matrix<T>::operator/(matrix &st)
//{
//
//}

template<typename T> matrix<T> matrix<T>::operator=(const matrix &st)
{
	if (n != st.n) cout << "n != st.n\n";
	else memcpy(this, st.arr, sizeof(T) * n * n);
	return *this;
}

template<typename T> ostream& operator<<<T>(ostream &stream, const matrix<T> &st)
{
	for (int i = 0; i < st.n; i++)
	{
		for (int j = 0; j < st.n; j++)
			stream << st.arr[i][j] << " ";
		stream << "\n";
	}
	return stream;
}

template<typename T> matrix<T> matrix<T>::inverse()
{
	matrix<T> ret(n);
	for (int i = 1; i < n; i++)
		for (int j = 1; j < n; j++)
			swap(ret[i][j], ret[j][i]);
	return ret;
}