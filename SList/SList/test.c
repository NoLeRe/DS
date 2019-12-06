#include"SList.h"


void test()
{
	SList *plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushFront(&plist, 0);
	//SListPopBack(&plist);
	SListPopFront(&plist);
	SListprint(plist);
	
}

int main()
{
	test();
	system("pause");
	return 0;

}