#include"SListNode.h"

int main()
{
	SListNode *p=NULL;
	SListPushBack(&p, 1);
	SListPushBack(&p, 2);
	SListPushBack(&p, 3);
	SListPushBack(&p, 4);
	SListPushFront(&p, 0);
	SListPopBack(&p);
	SListPopFront(&p);
	SListDestory(&p);
	SListPrint(p);
	system("pause");
	return 0;
}