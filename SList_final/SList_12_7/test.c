#include"SList.h"

void test()
{
	ListNode *plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	/*ListNode *new=SListFind(plist, 3);
	SListprint(new);*/
	SListInsertAfter(plist, 20);
	SListEraseAfter(plist);
	SListDestory(&plist);
	SListprint(plist);
}

int main()
{
	test();
	system("pause");
	return 0;
}