#pragma once
#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;


struct LinkNode
{
//protected:
	int data_molecule, data_denominator;//���� ��ĸ
	LinkNode *link;
//public:
	//LinkNode() { link = NULL; }
	LinkNode(int mol, int den)
	{
		data_molecule = mol;
		data_denominator = den;
		link = NULL;
	}

};
class list
{
protected:
	int count;
	LinkNode *first;
	LinkNode *last;		//ͷβ
public:
	list();
	~list() { makeEmpty(); delete first; }
	bool makeEmpty();
	bool insert(LinkNode *preNode,LinkNode *newNode);
	bool ferayFun(int num);
};
 
list::list()
{
	first = new LinkNode(0, 1);
	last = new LinkNode(1, 1);
	first->link = last;
	count = 2;   //���ڼ�¼���������ʼ���������
}
bool list::makeEmpty()//�ÿ�
{

	if (first->link == NULL)
	{
		delete first;
		return true;
	}

	LinkNode *p = NULL;

	while (first == NULL)
	{
		p = first;
		first = p->link;
		delete p;
	}
	return true;
}
bool list::insert(LinkNode *preNode,LinkNode *newNode)
{
	newNode->link = preNode->link;
	preNode->link = newNode;
	count++;                                  //ÿ����insert���� �����+1
	return true;
}
bool list::ferayFun(int num)
{
	int judge = 1;        //�޸��ж�����
	while (judge)
	{
		judge = 0;
		LinkNode *tempNode = first;
		LinkNode *p = tempNode->link;
		int a = count;
		for (int i = 1; i < a; i++)
		{
			if ((tempNode->data_denominator+p->data_denominator)<=num)
			{
				LinkNode *q = new LinkNode(tempNode->data_molecule + p->data_molecule,
					              tempNode->data_denominator + p->data_denominator);
				                                         //���ӷ�ĸ�ֱ����
				insert(tempNode, q);
				judge = 1;
			}
			tempNode = p;
			p = p->link;
		}
	}
	ofstream outData("data.txt", ios::out);
	LinkNode *r = first;
	while (r!=NULL)
	{
		outData << r->data_molecule << "/" << r->data_denominator << " ";
		r = r->link;
	}
	outData.close();
	return true;
}