#pragma once
#ifndef _INPUT_H_
#define _INPUT_H_

#include <vector>
#include <iostream>
using namespace::std;

class InputLine
{
public:
	int LineNumber = 0;		//��ˮ������
	int Linelength = 0;		//��ˮ��ÿ����������Ʒ��

	vector<vector<int>> InputData;	//1���ӵ�50��������ˮ�ߵ�����

	InputLine(int LineNum, int Linelen);
	void generateData();
	void output();
};

#endif 