#pragma once
//������Ȼ��a��b֮ż����
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
		if (i % 2 == 1)      //����һ��
			i++;
		while (i <= b)
		{
			cout << i << ' ';
			i += 2;
		}
		cout << endl;
	}
};