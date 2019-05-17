#include "Output.h"

OutputLine::OutputLine(int LineNum, int Linelen)
{
	LineNumber = LineNum;
	Linelength = Linelen;

	for (int i = 0; i < LineNumber; i++)
	{
		vector<int> subLine;
		OutputData.push_back(subLine);
	}
}

void OutputLine::getData(int line, int data)
{
	OutputData[line].push_back(data);
}

void OutputLine::output()
{
	int i, j;

	//print the data
	cout << "the output data is:" << endl;
	for (i = 0; i < LineNumber; i++)
	{
		cout << "line " << i << ": ";
		for (j = 0; j < Linelength - 1; j++)
		{
			cout << OutputData[i][j] << ", ";
		}
		cout << OutputData[i][j] << endl << endl;
	}
	cout << endl;
}

void OutputLine::clear()
{
	for (int i = 0; i < LineNumber; i++)
		OutputData[i].clear();
}