#pragma once
#ifndef _OUTPUT_H_
#define _OUTPUT_H_

#include <vector>
#include <iostream>
using namespace::std;

class OutputLine
{
public:
	int LineNumber = 0;		//��ˮ������
	int Linelength = 0;		//��ˮ��ÿ����������Ʒ��

	vector<vector<int>> OutputData;	//1���ӵ�50��������ˮ�ߵ�����

	OutputLine(int LineNum, int Linelen);
	void getData(int line, int data);
	void output();
	void clear();
};

#endif 