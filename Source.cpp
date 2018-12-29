#include "matrix.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<vector<int>> st(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			st[i].push_back(i * 3 + j);
	matrix<4, int> a(st);
	a.deter(0);
	//cout << a << "\n" << "determine is " << a.deter(0);
	system("pause");
	return 0;
}