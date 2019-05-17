#include "Duplicator.h"

vector<int>  Duplicator::copyData(int tempData)
{
	vector<int> copyData;
	for (int i = 0; i < length; i++)
	{
		copyData.push_back(tempData);
	}

	return copyData;
}

void Duplicator::setLength(int len)
{
	length = len;
}