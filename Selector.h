#pragma once
#ifndef _SELECTOR_H_
#define _SELECTOR_H_

#include <vector>
#include <iostream>
using namespace::std;

class Selector
{
public:
	int pos = 0;  //ѡ��ڼ�����Ʒ
	vector<int> Data;

	void getData(int data);
	int selectData();

	void setPos(int POS);
};

#endif 