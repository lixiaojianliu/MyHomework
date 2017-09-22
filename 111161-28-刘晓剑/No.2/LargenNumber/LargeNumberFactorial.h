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
	bool Reverse();						//逆置链表
	void facttorial(int x);
//	LinkNode * Locate(int i);
	//LinkNode* GetHead() { return first; }
	//LinkNode* GetTail() { return Tail; }
};
template <class T>
bool list<T>::makeEmpty()                //清空
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
bool list<T>::Reverse()											//逆置
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
	first->link = new LinkNode<int>(1);                          //将这个数本身放在第一个结点的数据中
	int count = 1;//节点数
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
			else if (p->data > 999 && p->link != NULL)//若p结点后不为空 则将该节点赋给newNode
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
	ofstream out("data.txt", ios::out);              //输出到文件
		out << "结点个数为："<<count << endl;
	out << ptr->data;
	ptr = ptr->link; //第一个数 不用考虑是否为三位
	while (ptr)              //输出
	{
		out << "," << setfill('0') << setw(3) << ptr->data;
		ptr = ptr->link;
	}
	out.close();
}
