#include "Warehouse.h"

//Warehouse::Warehouse(vector<int> &Data)
//{
//	tempData.insert(tempData.begin(), Data.begin(), Data.end());
//}

void Warehouse::inputData(int data)
{
	Data.push_back(data);
}

int Warehouse::outputData()
{
	int data=Data[0];
	Data.erase(Data.begin());
	return data;
}

void Warehouse::setIsOpen(bool IS)
{
	isOpen = IS;
}

void Warehouse::updateState()
{
	if (isOpen == true)
		isOpen = false;
	else
		isOpen = true;
}

bool Warehouse::changeOrder(int pos1, int pos2)
{
	int Length = (int)(Data.size());
	if (pos1 > (Length - 1) || pos2 > (Length - 1))
		return false;

	swap(Data[pos1], Data[pos2]);
	return true;
}

bool Warehouse::copyData(int pos, int startPos, int endPos)
{
	int Length = (int)(Data.size());
	if (pos > (Length - 1) || startPos > endPos || endPos > (Length - 1))
		return false;

	int temp = Data[pos];
	for (int i = startPos; i <= endPos; i++)
		Data[i] = temp;
	return true;
}

bool Warehouse::deleteData(int pos)
{
	int Length = (int)(Data.size());
	if (pos > (Length - 1))
		return false;

	Data[pos] = -1;
	return true;
}