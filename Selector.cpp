#include "Selector.h"

int Selector::selectData()
{
	int temp;
	int length = (int)(Data.size());
	if (pos < length)
	{
		temp = Data[pos];
		Data.clear();
		return temp;
	}
	if (pos >= length)
	{
		pos = length / 2;
		temp = Data[pos];
		Data.clear();
		return temp;
	}	
}

void Selector::getData(int data)
{
	Data.push_back(data);
}

void Selector::setPos(int POS)
{
	pos = POS;
}