#include "Input.h"
#define N  999


InputLine::InputLine(int LineNum, int Linelen)
{
	LineNumber = LineNum;
	Linelength = Linelen;

	for (int i = 0; i < LineNumber; i++)
	{
		vector<int> subLine;
		InputData.push_back(subLine);
	}
}

void InputLine::generateData()
{
	int i, j, randData;
	float randNum;

	//delete data
	for (i = 0; i < LineNumber; i++)
		InputData[i].clear();

	//update data
	for (i = 0; i < LineNumber; i++)
	{
		for (j = 0; j < Linelength; j++)
		{
			//randNum = rand() % (N + 1) / (float)(N + 1);
			//if (randNum <= 0.1)
			//	InputData[i].push_back(-1);		//-1表示空
			//if (randNum > 0.1)
			//{
			//	randData = rand() % 10000 + 1;
			//	InputData[i].push_back(randData); //存一个1到10000的数做产品id
			//}	
			int data = i * 100 + j;
			InputData[i].push_back(data);  //万位和千位表示在哪条流线水线上，十分位和个位表示是流水线上的第几个产品
		}
	}
}

void InputLine::output()
{
	int i, j;

	//print the data
	cout << "the input data is:" << endl;
	for (i = 0; i < LineNumber; i++)
	{
		cout << "line " << i << ": ";
		for (j = 0; j < Linelength-1; j++)
		{
			cout << InputData[i][j] << ", ";
		}
		cout << InputData[i][j] << endl << endl;
	}
	cout << endl;
}