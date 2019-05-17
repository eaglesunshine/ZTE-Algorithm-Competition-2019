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
			//	InputData[i].push_back(-1);		//-1��ʾ��
			//if (randNum > 0.1)
			//{
			//	randData = rand() % 10000 + 1;
			//	InputData[i].push_back(randData); //��һ��1��10000��������Ʒid
			//}	
			int data = i * 100 + j;
			InputData[i].push_back(data);  //��λ��ǧλ��ʾ����������ˮ���ϣ�ʮ��λ�͸�λ��ʾ����ˮ���ϵĵڼ�����Ʒ
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