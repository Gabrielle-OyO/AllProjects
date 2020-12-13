#pragma once
//计算自然数a，b之奇数和
#include<iostream>
using namespace std;
class data
{
private:
	int a, b;
public:
	data(int x, int y) { a = x;b = y; }
	void exec()
	{
		int i = a;
		if (i % 2 == 0)
			i++;
		while (i <= b)
		{
			cout << i << ' ';
			i += 2;
		}
		cout << endl;
	}
};