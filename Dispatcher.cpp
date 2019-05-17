#include "Dispatcher.h"

Dispatcher::Dispatcher(int WarehouseNumber, int DuplicatorNumber, int SelectorNumber)
{
	int Max = WarehouseNumber;
	if (Max < DuplicatorNumber)
		Max = DuplicatorNumber;
	if (Max < SelectorNumber)
		Max = SelectorNumber;

	for (int i = 0; i < Max; i++)
	{
		if (i < WarehouseNumber)
		{
			Warehouse tempWarehouse;
			WarehouseAll.push_back(tempWarehouse);
		}
		if (i < DuplicatorNumber)
		{
			Duplicator tempDuplicator;
			DuplicatorAll.push_back(tempDuplicator);
		}
		if (i < SelectorNumber)
		{
			Selector tempSelector;
			SelectorAll.push_back(tempSelector);
		}
	}
}

void Dispatcher::setParameter()
{
	int i;

	//对仓库设置
	for (i = 50; i < 100; i++)
		WarehouseAll[i].setIsOpen(false);
	for (i = 3100; i < 6100; i++)
		WarehouseAll[i].setIsOpen(false);

	//对复制器的设置
	for (i = 0; i < 50; i++)
		DuplicatorAll[i].setLength(2);
	for (i = 50; i < 100; i++)
		DuplicatorAll[i].setLength(3000);
	for (i = 100; i < 3100; i++)
		DuplicatorAll[i].setLength(2);
	for (i = 3100; i < 6100; i++)
		DuplicatorAll[i].setLength(50);

	//对选择器设置
	for (i = 0; i < 3000; i++)
	{
		int pos = i % 50;
		SelectorAll[i].setPos(pos);
	}
}

bool Dispatcher::dispatchMain()
{
	int i, j, k, n, count;
	vector<int> tempData;

	InputLine InLine(50,60);
	OutputLine OutLine(50, 60);
	
	//设置复制器、选择器参数
	setParameter();

	count = 0;
	while (count < 4)  //循环10分钟
	{
		/********对每1分钟输入的处理***********/
		//生成数据
		InLine.generateData();
		
		//打印输入
		InLine.output();

		//第一个60s,读入数据:输入线*50->复制器*50->仓库*100
		for (i = 0; i < 60; i++)
		{
			for (j = 0; j < 50; j++)
			{
				tempData.clear();
				//输入线->复制器
				tempData = DuplicatorAll[j].copyData(InLine.InputData[j][i]);
				//复制器->仓库
				if (WarehouseAll[j].isOpen == true)
					WarehouseAll[j].inputData(tempData[0]);
				if (WarehouseAll[j].isOpen == false)
					WarehouseAll[j + 50].inputData(tempData[1]);
			}
		}
		//更新仓库状态，交替输入/输出
		for (j = 0; j < 6100; j++)
			WarehouseAll[j].updateState();

		//第二个60s,导出成50*60的数据仓库:仓库*100->复制器*50->选择器*3000->复制器*3000->仓库*6000
		for (i = 0; i < 60; i++)
		{
			for (j = 0; j < 50; j++)
			{
				tempData.clear();
				//仓库->复制器
				if (WarehouseAll[j].isOpen == false)
					tempData = DuplicatorAll[j + 50].copyData(WarehouseAll[j].outputData());
				if (WarehouseAll[j].isOpen == true)
					tempData = DuplicatorAll[j + 50].copyData(WarehouseAll[j + 50].outputData());
				//复制器->选择器
				for (k = 0; k < 3000; k++)
					SelectorAll[k].getData(tempData[k]);
			}
			//选择器->复制器->仓库
			for (k = 0; k < 3000; k++)
			{
				int data = SelectorAll[k].selectData();
				tempData.clear();
				tempData = DuplicatorAll[k + 100].copyData(data);
				if (WarehouseAll[k + 100].isOpen == true)
					WarehouseAll[k + 100].inputData(tempData[0]);
				if (WarehouseAll[k + 100].isOpen == false)
					WarehouseAll[k + 3100].inputData(tempData[1]);
			}
		}
		//仓库数据复制
		for (k = 0; k < 3000; k++)
		{
			if (WarehouseAll[k + 100].isOpen == true)
			{
				int pos = k / 50;
				WarehouseAll[k + 100].copyData(pos, 0, (int)(WarehouseAll[k + 100].Data.size()) - 1);
			}
			if (WarehouseAll[k + 100].isOpen == false)
			{
				int pos = k / 50;
				WarehouseAll[k + 3100].copyData(pos, 0, (int)(WarehouseAll[k + 3100].Data.size()) - 1);
			}
		}
		//更新仓库状态，交替输入/输出
		for (j = 0; j < 6100; j++)
			WarehouseAll[j].updateState();

		//第三个60s，输出数据:仓库*6000->复制器*3000->选择器*50->输出线*50
		for (i = 0; i < 60; i++)
		{
			//仓库->复制器->选择器
			for (k = 0; k < 3000; k++)
			{
				if (WarehouseAll[k + 100].isOpen == false)
				{
					tempData.clear();
					tempData = DuplicatorAll[k + 3100].copyData(WarehouseAll[k + 100].outputData());
					for (n = 0; n < 50; n++)
					{
						SelectorAll[n + 3000].getData(tempData[n]);
					}
				}
				if (WarehouseAll[k + 100].isOpen == true)
				{
					tempData.clear();
					tempData = DuplicatorAll[k + 3100].copyData(WarehouseAll[k + 3100].outputData());
					for (n = 0; n < 50; n++)
					{
						SelectorAll[n + 3000].getData(tempData[n]);
					}
				}
			}
			//选择器->输出线
			for (n = 0; n < 50; n++)
			{
				/**********************实现控制************************/
				if (count == 0)
				{
					if(n == 0 && i == 0)
						cout << "实现原序输出" << endl;
					SelectorAll[n + 3000].setPos(i * 50 + n);  //实现原序输出
				}
				if (count == 1)
				{
					if (n == 0 && i == 0)
						cout << "实现线间逆序输出" << endl;
					SelectorAll[n + 3000].setPos(i * 50 + 49 - n);	//实现线间逆序输出
				}
				if (count == 2)
				{
					if (n == 0 && i == 0)
						cout << "实现线内逆序输出" << endl;
					SelectorAll[n + 3000].setPos((59 - i) * 50 + n);	//实现线内逆序输出
				}
				if (count == 3)
				{
					if (n == 0 && i == 0)
						cout << "实现线间逆序+线内逆序输出" << endl;
					SelectorAll[n + 3000].setPos((59 - i) * 50 + 49 - n);	//实现线间逆序+线内逆序输出
				}			
				/**********************实现控制************************/

				int data = SelectorAll[n + 3000].selectData();
				OutLine.getData(n, data);
			}
		}
		//更新仓库状态，交替输入/输出
		for (j = 0; j < 6100; j++)
			WarehouseAll[j].updateState();

		//打印输出
		OutLine.output();

		//清空输出线
		OutLine.clear();

		++count;
	}

	return true;
}