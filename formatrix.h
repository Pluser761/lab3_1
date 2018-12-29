#pragma once
#include <iostream>

using namespace std;

void GetMatr(int **mas, int **p, int i, int j, int m)
{
	int ki, kj, di, dj;
	di = 0;
	for (ki = 0; ki < m - 1; ki++)
	{ // проверка индекса строки
		if (ki == i) di = 1;
		dj = 0;
		for (kj = 0; kj < m - 1; kj++)
		{ // проверка индекса столбца
			if (kj == j) dj = 1;
			p[ki][kj] = mas[ki + di][kj + dj];
		}
	}
}

int Determinant(int **mas, int m)
{
	int i, j, d, k, n;
	int **p;
	p = new int*[m];
	for (i = 0; i < m; i++) p[i] = new int[m];
	j = 0; d = 0;
	k = 1; //(-1) в степени i
	n = m - 1;
	if (m < 1) cout << "Определитель вычислить невозможно!";
	if (m == 1)
	{
		d = mas[0][0];
		return(d);
	}
	if (m == 2)
	{
		d = mas[0][0] * mas[1][1] - (mas[1][0] * mas[0][1]);
		return(d);
	}
	if (m > 2)
	{
		for (i = 0; i < m; i++)
		{
			GetMatr(mas, p, i, 0, m);
			d = d + k * mas[i][0] * Determinant(p, n);
			k = -k;
		}
	}
	return(d);
}