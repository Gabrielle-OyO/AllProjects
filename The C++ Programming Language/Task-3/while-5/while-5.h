#pragma once
//计算自然数a，b之偶数和
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
		if (i % 2 == 1)      //改这一行
			i++;
		while (i <= b)
		{
			cout << i << ' ';
			i += 2;
		}
		cout << endl;
	}
};