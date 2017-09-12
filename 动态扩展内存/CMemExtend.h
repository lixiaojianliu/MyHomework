
#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
#include "stdio.h"
using namespace std;

class CMemExtend
{
private:
	char * m_pvBuf;//记录内容
	long ICurBytesNum;//当前内存所含字节数
	string character;//用户输入字符
	unsigned long SizeOfcharacter;//用户输入字符的大小
public:
	CMemExtend()//构造函数，初始化变量
	{
		m_pvBuf = 0;
		ICurBytesNum = 0;
		SizeOfcharacter = 0;
	}

	~CMemExtend() { delete [] m_pvBuf; }//析构函数

	void GetCharacter()//函数，获取字符
	{
		cout << "请输入一段字符串：" << endl;
		getline(cin,character);//用户输入字符
		SizeOfcharacter = character.length();//计算长度

	}
	void *GetMenBuf(long IMemSize)//判断是否满足需求，及反应方式
	{
		cout << "请输入所需字节数" << endl;
		cin >> IMemSize;
		if (IMemSize > SizeOfcharacter + 1)//用户指定内存大于实际内存
		{
			ICurBytesNum=SizeOfcharacter +1;//将字符串长度赋予当前字符串长度
			m_pvBuf = new char[ICurBytesNum];
			strcpy_s(m_pvBuf, ICurBytesNum,character.c_str());
			return m_pvBuf;
		}
		else//用户指定的字符数不足
		{
			ICurBytesNum = SizeOfcharacter + 1;//将实际长度值赋予当前长度
			m_pvBuf = new char[ICurBytesNum];
			strcpy_s(m_pvBuf, ICurBytesNum, character.c_str());
			return m_pvBuf;
		}

	}
	void read()//输出信息
	{
		cout << "实际所占内存大小："<<ICurBytesNum << endl;
		cout << "内容为：" << endl;
		for (int i = 0; i < ICurBytesNum; i++)
			cout << m_pvBuf[i] << " ";

	}
};