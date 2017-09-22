#pragma once
#include "stdafx.h"
using namespace std;
#include <iostream>

class LinkNode
{
public:
	LinkNode() { link = NULL; data = 0; }
	LinkNode(int DATA, LinkNode *LINK) { data = DATA; link = LINK; }
	int data;
	LinkNode *link;

};

class list
{
protected:
//public:
	LinkNode *first, *Tail;
public:
	list() { first = new LinkNode; }
	~list() { makeEmpty(); };
	bool makeEmpty();
	void InPut();	//������������
	bool merge(list &list2);		//�ϲ�����
	void OutPut();						//�����������
	int Remove(LinkNode *removed);    //�Ƴ����
	bool Sort();                        //����
	int GetLength();   //��ȡ����
	void OrderInsert(int x);          //�������
	bool Reverse();						//��������
	LinkNode * Locate(int i);
	LinkNode* GetHead() { return first; }
	LinkNode* GetTail() { return Tail; }
};


void list::InPut()
{
	LinkNode *p = new LinkNode;
	p->link = first;
	first = p;
	int count, pdata;
	cout << "����������Ԫ�ظ���" << endl;
	cin >> count;
	cout << "������" << endl;
	for (int i = 0; i < count; i++)
	{
		LinkNode *NewNode = new LinkNode;
		cin >> pdata;
		NewNode->data = pdata;
		p->link = NewNode;
		p = NewNode;
	  }
	Tail = p;
	//cout << p->data;
}

bool list::merge(list &list2)
{
	//LinkNode *ptr1 = first;//��ȡ�������ͷ���
	LinkNode *ptr2 = list2.GetHead();//��ȡ����2��ͷ���
	Tail->link= ptr2->link;//���������βָ������2�ĵڶ������
	delete ptr2;
	return true;


//	LinkNode *newNode = new LinkNode;
	//newNode->link = first;
	//while (ptr1!=NULL&&ptr2!=NULL)
	//{
	//	if (ptr1->data<ptr2->data)
	//	{
	//		newNode->link = ptr1;
	//		ptr1 = ptr1->link;
	//	}
	//	else
	//	{
	//		newNode->link = ptr2;
	//		ptr2 = ptr2->link;
	//	}
	//	newNode = newNode->link;
	//}

}
void list::OutPut()
{
	LinkNode *oNode;
	oNode = first->link;
	//first->data = NULL; first����˸����� ���Ա���
	//first = oNode;

	while (oNode != NULL)
	{
		cout << oNode->data << " ";
		oNode = oNode->link;
	}
	while (oNode)
	{
		cerr << "�������ʧ��" << endl;

	}
	cout <<  endl;

}

int list::Remove(LinkNode *removed)             //�Ƴ�����Ľ�㣬�����ظýڵ������
{
	if (removed->link == NULL)    //��������һ�����
	{
		LinkNode *temp;
		//LinkNode *temp1;
		temp=Locate(GetLength()-1);
		//temp1 = temp->link;
		int a = temp->link->data;
		delete temp->link;
		temp->link = NULL;
		return a;
	}
	LinkNode *pnext = removed->link;  
	LinkNode *temp;
	temp = pnext;
	int a = removed->data;
	removed->data = pnext->data;
	removed->link = pnext->link;
	delete temp;
	return a;
}

int list::GetLength()
{//��ȡ����
	LinkNode *p = first->link;
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p->link;
	}
	return count;
}
void list::OrderInsert(int x) //�������ֵ
{
	LinkNode *curr, *pre;
	//��ʼ��
	curr = first->link;	//currָ��������һ�����
	pre = first;		//preָ��ͷ���
						//��λ����λ��
	while (curr != NULL && curr->data <= x)
	{
		pre = curr;
		curr = curr->link;
	}
	LinkNode *newNode = new LinkNode(x, pre->link);//����һ����㲢��ֵ
	pre->link = newNode;		         //���½�������pre��ָ����
}
 LinkNode * list::Locate(int i)
{
	if (i < 0) return NULL;
	LinkNode * current = first;
	int k = 0;
	while (current != NULL && k < i)
	{
		current = current->link;
		k++;
	}
	return current;
}
bool list::makeEmpty()
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


bool list::Sort()
{
	LinkNode *tempNode = first->link;
	//LinkNode *preNode = first;
	list temp;
	while (tempNode!=NULL)
	{
		temp.OrderInsert(this->Remove(tempNode));
		tempNode = first->link;
	}
	//temp.OutPut();
	first = temp.first;
	return false;
}
bool list::Reverse()
{
	LinkNode *p, *q, *r;
	p = first->link;
	q = NULL; 
	while (p!=NULL)
	{
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	first->link = q;

	return true;

}