// LinkList3.0.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "list.h"


int main()
{
	list test1, test2;
	test1.InPut();
	test2.InPut();
	test1.merge(test2);
	cout << "�ϲ��������Ϊ��";
	test1.OutPut();
	test1.Sort();
	cout << "����������Ϊ��";
	test1.OutPut();
	test1.Reverse();
	cout << "���ú������Ϊ��";
	test1.OutPut();
	system("pause");
    return 0;
}

