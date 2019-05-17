#pragma once
#ifndef _OUTPUT_H_
#define _OUTPUT_H_

#include <vector>
#include <iostream>
using namespace::std;

class OutputLine
{
public:
	int LineNumber = 0;		//流水线条数
	int Linelength = 0;		//流水线每分钟生产产品数

	vector<vector<int>> OutputData;	//1分钟的50条输入流水线的数据

	OutputLine(int LineNum, int Linelen);
	void getData(int line, int data);
	void output();
	void clear();
};

#endif 