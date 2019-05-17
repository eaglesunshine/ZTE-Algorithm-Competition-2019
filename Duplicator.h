#pragma once
#ifndef _DUPLICATOR_H_
#define _DUPLICATOR_H_

#include <vector>
#include <iostream>
using namespace::std;

class Duplicator
{
public:
	int length = 0;  //复制的份数
	vector<int>  copyData(int tempData);

	void setLength(int len);
};

#endif 