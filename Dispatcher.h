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

	bool dispatchMain();  //�����Ⱥ���
	void setParameter();  //���ø�������ѡ��������

	Dispatcher(int WarehouseNumber,int DuplicatorNumber,int SelectorNumber);
};

#endif 