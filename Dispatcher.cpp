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

	//�Բֿ�����
	for (i = 50; i < 100; i++)
		WarehouseAll[i].setIsOpen(false);
	for (i = 3100; i < 6100; i++)
		WarehouseAll[i].setIsOpen(false);

	//�Ը�����������
	for (i = 0; i < 50; i++)
		DuplicatorAll[i].setLength(2);
	for (i = 50; i < 100; i++)
		DuplicatorAll[i].setLength(3000);
	for (i = 100; i < 3100; i++)
		DuplicatorAll[i].setLength(2);
	for (i = 3100; i < 6100; i++)
		DuplicatorAll[i].setLength(50);

	//��ѡ��������
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
	
	//���ø�������ѡ��������
	setParameter();

	count = 0;
	while (count < 4)  //ѭ��10����
	{
		/********��ÿ1��������Ĵ���***********/
		//��������
		InLine.generateData();
		
		//��ӡ����
		InLine.output();

		//��һ��60s,��������:������*50->������*50->�ֿ�*100
		for (i = 0; i < 60; i++)
		{
			for (j = 0; j < 50; j++)
			{
				tempData.clear();
				//������->������
				tempData = DuplicatorAll[j].copyData(InLine.InputData[j][i]);
				//������->�ֿ�
				if (WarehouseAll[j].isOpen == true)
					WarehouseAll[j].inputData(tempData[0]);
				if (WarehouseAll[j].isOpen == false)
					WarehouseAll[j + 50].inputData(tempData[1]);
			}
		}
		//���²ֿ�״̬����������/���
		for (j = 0; j < 6100; j++)
			WarehouseAll[j].updateState();

		//�ڶ���60s,������50*60�����ݲֿ�:�ֿ�*100->������*50->ѡ����*3000->������*3000->�ֿ�*6000
		for (i = 0; i < 60; i++)
		{
			for (j = 0; j < 50; j++)
			{
				tempData.clear();
				//�ֿ�->������
				if (WarehouseAll[j].isOpen == false)
					tempData = DuplicatorAll[j + 50].copyData(WarehouseAll[j].outputData());
				if (WarehouseAll[j].isOpen == true)
					tempData = DuplicatorAll[j + 50].copyData(WarehouseAll[j + 50].outputData());
				//������->ѡ����
				for (k = 0; k < 3000; k++)
					SelectorAll[k].getData(tempData[k]);
			}
			//ѡ����->������->�ֿ�
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
		//�ֿ����ݸ���
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
		//���²ֿ�״̬����������/���
		for (j = 0; j < 6100; j++)
			WarehouseAll[j].updateState();

		//������60s���������:�ֿ�*6000->������*3000->ѡ����*50->�����*50
		for (i = 0; i < 60; i++)
		{
			//�ֿ�->������->ѡ����
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
			//ѡ����->�����
			for (n = 0; n < 50; n++)
			{
				/**********************ʵ�ֿ���************************/
				if (count == 0)
				{
					if(n == 0 && i == 0)
						cout << "ʵ��ԭ�����" << endl;
					SelectorAll[n + 3000].setPos(i * 50 + n);  //ʵ��ԭ�����
				}
				if (count == 1)
				{
					if (n == 0 && i == 0)
						cout << "ʵ���߼��������" << endl;
					SelectorAll[n + 3000].setPos(i * 50 + 49 - n);	//ʵ���߼��������
				}
				if (count == 2)
				{
					if (n == 0 && i == 0)
						cout << "ʵ�������������" << endl;
					SelectorAll[n + 3000].setPos((59 - i) * 50 + n);	//ʵ�������������
				}
				if (count == 3)
				{
					if (n == 0 && i == 0)
						cout << "ʵ���߼�����+�����������" << endl;
					SelectorAll[n + 3000].setPos((59 - i) * 50 + 49 - n);	//ʵ���߼�����+�����������
				}			
				/**********************ʵ�ֿ���************************/

				int data = SelectorAll[n + 3000].selectData();
				OutLine.getData(n, data);
			}
		}
		//���²ֿ�״̬����������/���
		for (j = 0; j < 6100; j++)
			WarehouseAll[j].updateState();

		//��ӡ���
		OutLine.output();

		//��������
		OutLine.clear();

		++count;
	}

	return true;
}