#pragma once
#ifndef _WAREHOUSE_H_
#define _WAREHOUSE_H_

#include <vector>
#include <iostream>
using namespace::std;

class Warehouse
{
public:
	bool isOpen = true;    //true��ʾ����״̬��false��ʾ���״̬
	vector<int> Data;

	void inputData(int data);
	int outputData();
	void updateState();
	void setIsOpen(bool IS);

	bool changeOrder(int pos1, int pos2);	//λ�򽻻�
	bool copyData(int pos,int startPos,int endPos);	//���Ʋ�Ʒ
	bool deleteData(int pos);	//�ÿ�

	//Warehouse(vector<int> &Data);
};

#endif 