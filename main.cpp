#include "Dispatcher.h"
#include <iostream>

using namespace::std;

int main()
{
	Dispatcher Dispatch(6100, 6100, 3050); //依次对应仓库数目、复制器数目、选择器数目
	Dispatch.dispatchMain();	//执行调度函数

	system("pause");
	return 0;
}