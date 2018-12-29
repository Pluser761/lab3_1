#include "matrix.h"
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int main()
{
	srand(time(0));
	vector<vector<int>> st(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (i == j) st[i].push_back(1);
			else st[i].push_back(0);
	matrix<int> a(st);
	cout << a << "\n" << deter(a) << endl;
	system("pause");
	return 0;
}