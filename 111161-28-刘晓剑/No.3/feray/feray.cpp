// feray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "法雷序列.h"

int main()
{
	list test;
	int n;
	cout << "请输入要计算的法雷数:" ;
	cin >> n;
	test.ferayFun(n);
	cout << "计算完成" << endl;
	system("pause");
    return 0;
}

