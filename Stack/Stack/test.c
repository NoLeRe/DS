#include"Stack.h"




int main()
{
	Stack ps;
	StackInit(&ps);
	StackPush(&ps, 1);
	StackPush(&ps, 2);
	StackPush(&ps, 3);
	StackPrint(&ps);
	system("pause");
	return 0;
}