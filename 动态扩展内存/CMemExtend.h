
#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
#include "stdio.h"
using namespace std;

class CMemExtend
{
private:
	char * m_pvBuf;//��¼����
	long ICurBytesNum;//��ǰ�ڴ������ֽ���
	string character;//�û������ַ�
	unsigned long SizeOfcharacter;//�û������ַ��Ĵ�С
public:
	CMemExtend()//���캯������ʼ������
	{
		m_pvBuf = 0;
		ICurBytesNum = 0;
		SizeOfcharacter = 0;
	}

	~CMemExtend() { delete [] m_pvBuf; }//��������

	void GetCharacter()//��������ȡ�ַ�
	{
		cout << "������һ���ַ�����" << endl;
		getline(cin,character);//�û������ַ�
		SizeOfcharacter = character.length();//���㳤��

	}
	void *GetMenBuf(long IMemSize)//�ж��Ƿ��������󣬼���Ӧ��ʽ
	{
		cout << "�����������ֽ���" << endl;
		cin >> IMemSize;
		if (IMemSize > SizeOfcharacter + 1)//�û�ָ���ڴ����ʵ���ڴ�
		{
			ICurBytesNum=SizeOfcharacter +1;//���ַ������ȸ��赱ǰ�ַ�������
			m_pvBuf = new char[ICurBytesNum];
			strcpy_s(m_pvBuf, ICurBytesNum,character.c_str());
			return m_pvBuf;
		}
		else//�û�ָ�����ַ�������
		{
			ICurBytesNum = SizeOfcharacter + 1;//��ʵ�ʳ���ֵ���赱ǰ����
			m_pvBuf = new char[ICurBytesNum];
			strcpy_s(m_pvBuf, ICurBytesNum, character.c_str());
			return m_pvBuf;
		}

	}
	void read()//�����Ϣ
	{
		cout << "ʵ����ռ�ڴ��С��"<<ICurBytesNum << endl;
		cout << "����Ϊ��" << endl;
		for (int i = 0; i < ICurBytesNum; i++)
			cout << m_pvBuf[i] << " ";

	}
};