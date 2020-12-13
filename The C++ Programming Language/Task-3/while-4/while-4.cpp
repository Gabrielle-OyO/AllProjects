#include<iostream>
using namespace std;
#include"while-4.h"
int main()
{
	int x, y;
	cin >> x >> y;
	data A(x, y);     //什么错误？如何改正？
	A.exec();
	return 0;
}