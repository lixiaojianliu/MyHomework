// LinkList3.0.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "list.h"


int main()
{
	list test1, test2;
	test1.InPut();
	test2.InPut();
	test1.merge(test2);
	cout << "合并后的链表为：";
	test1.OutPut();
	test1.Sort();
	cout << "排序后的链表为：";
	test1.OutPut();
	test1.Reverse();
	cout << "逆置后的链表为：";
	test1.OutPut();
	system("pause");
    return 0;
}

