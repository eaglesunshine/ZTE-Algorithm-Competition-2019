#include "Dispatcher.h"
#include <iostream>

using namespace::std;

int main()
{
	Dispatcher Dispatch(6100, 6100, 3050); //���ζ�Ӧ�ֿ���Ŀ����������Ŀ��ѡ������Ŀ
	Dispatch.dispatchMain();	//ִ�е��Ⱥ���

	system("pause");
	return 0;
}