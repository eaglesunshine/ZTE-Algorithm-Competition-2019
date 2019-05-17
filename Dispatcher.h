#pragma once
#ifndef _DISPATCHER_H_
#define _DISPATCHER_H_

#include "Input.h"
#include "Output.h"
#include "Warehouse.h"
#include "Duplicator.h"
#include "Selector.h"
#include <vector>
#include <iostream>
using namespace::std;

class Dispatcher
{
public:
	vector<Warehouse> WarehouseAll;
	vector<Duplicator> DuplicatorAll;
	vector<Selector> SelectorAll;

	bool dispatchMain();  //主调度函数
	void setParameter();  //设置复制器、选择器参数

	Dispatcher(int WarehouseNumber,int DuplicatorNumber,int SelectorNumber);
};

#endif 