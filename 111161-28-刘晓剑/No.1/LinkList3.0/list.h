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
	void InPut();	//输入链表数据
	bool merge(list &list2);		//合并链表
	void OutPut();						//输出链表数据
	int Remove(LinkNode *removed);    //移除结点
	bool Sort();                        //排序
	int GetLength();   //获取长度
	void OrderInsert(int x);          //有序插入
	bool Reverse();						//逆置链表
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
	cout << "请输入链表元素个数" << endl;
	cin >> count;
	cout << "请输入" << endl;
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
	//LinkNode *ptr1 = first;//获取该链表的头结点
	LinkNode *ptr2 = list2.GetHead();//获取链表2的头结点
	Tail->link= ptr2->link;//将该链表的尾指向链表2的第二个结点
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
	//first->data = NULL; first里存了个数据 所以报错
	//first = oNode;

	while (oNode != NULL)
	{
		cout << oNode->data << " ";
		oNode = oNode->link;
	}
	while (oNode)
	{
		cerr << "链表输出失败" << endl;

	}
	cout <<  endl;

}

int list::Remove(LinkNode *removed)             //移除传入的结点，并返回该节点的数据
{
	if (removed->link == NULL)    //如果是最后一个结点
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
{//获取长度
	LinkNode *p = first->link;
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p->link;
	}
	return count;
}
void list::OrderInsert(int x) //有序插入值
{
	LinkNode *curr, *pre;
	//初始化
	curr = first->link;	//curr指向该链表第一个结点
	pre = first;		//pre指向头结点
						//定位插入位置
	while (curr != NULL && curr->data <= x)
	{
		pre = curr;
		curr = curr->link;
	}
	LinkNode *newNode = new LinkNode(x, pre->link);//申请一个结点并赋值
	pre->link = newNode;		         //把新结点插入在pre所指结点后
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