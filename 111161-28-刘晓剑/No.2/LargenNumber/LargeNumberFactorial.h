#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include "stdafx.h"
using namespace std;

template <class T>
struct LinkNode
{
	LinkNode(LinkNode<T> *ptr = NULL) { link = ptr; }
	LinkNode(const T item, LinkNode<T> *ptr = NULL) { data = item; link = ptr; }
	T data;
	LinkNode<T> *link;

};
template <class T>
class list
{
protected:
	LinkNode<T> *first;
public:
	list() { first = new LinkNode<T>; }
	~list() { makeEmpty(); };
	bool makeEmpty();
	bool Reverse();						//��������
	void facttorial(int x);
//	LinkNode * Locate(int i);
	//LinkNode* GetHead() { return first; }
	//LinkNode* GetTail() { return Tail; }
};
template <class T>
bool list<T>::makeEmpty()                //���
{
	if (first->link == NULL)
	{
		delete first;
		return true;
	}
	LinkNode<T> *p;
	while (first->link!=NULL)
	{
		
		p = first->link;
		first->link = p->link;
		delete p;
	}
	return true;
}
template <class T>
bool list<T>::Reverse()											//����
{
	LinkNode<T> *p, *q, *r;
	p = first->link;
	q = NULL;
	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	first->link = q;
	return true;

}
template <class T>
void list<T>::facttorial(int num)
{
	first->link = new LinkNode<int>(1);                          //�������������ڵ�һ������������
	int count = 1;//�ڵ���
	for (int i = num; i>0; i--)
	{
		LinkNode<int> *p=first->link;
		while (p != NULL)
		{
			p->data *= i;
			p = p->link;
		}
		p = first->link;
		while (p != NULL)
		{
			if (p->data > 999 && p->link == NULL)
			{
				LinkNode<int> *newnode = new LinkNode<int>(0);
				p->link = newnode;
				newnode->data = newnode->data + p->data / 1000;
				p->data = p->data % 1000;
				count++;
			}
			else if (p->data > 999 && p->link != NULL)//��p����Ϊ�� �򽫸ýڵ㸳��newNode
			{
				LinkNode<int> *newNode;
				newNode = p->link;
				newNode->data = newNode->data + p->data / 1000;
				p->data = p->data % 1000;
			}
			p = p->link;
		}
	}
	Reverse();
	LinkNode<T> *ptr = first->link;
	ofstream out("data.txt", ios::out);              //������ļ�
		out << "������Ϊ��"<<count << endl;
	out << ptr->data;
	ptr = ptr->link; //��һ���� ���ÿ����Ƿ�Ϊ��λ
	while (ptr)              //���
	{
		out << "," << setfill('0') << setw(3) << ptr->data;
		ptr = ptr->link;
	}
	out.close();
}
