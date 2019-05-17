#pragma once
#ifndef _INPUT_H_
#define _INPUT_H_

#include <vector>
#include <iostream>
using namespace::std;

class InputLine
{
public:
	int LineNumber = 0;		//流水线条数
	int Linelength = 0;		//流水线每分钟生产产品数

	vector<vector<int>> InputData;	//1分钟的50条输入流水线的数据

	InputLine(int LineNum, int Linelen);
	void generateData();
	void output();
};

#endif 