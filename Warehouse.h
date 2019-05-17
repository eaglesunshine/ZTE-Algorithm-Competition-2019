#pragma once
#ifndef _WAREHOUSE_H_
#define _WAREHOUSE_H_

#include <vector>
#include <iostream>
using namespace::std;

class Warehouse
{
public:
	bool isOpen = true;    //true表示输入状态，false表示输出状态
	vector<int> Data;

	void inputData(int data);
	int outputData();
	void updateState();
	void setIsOpen(bool IS);

	bool changeOrder(int pos1, int pos2);	//位序交换
	bool copyData(int pos,int startPos,int endPos);	//复制产品
	bool deleteData(int pos);	//置空

	//Warehouse(vector<int> &Data);
};

#endif 