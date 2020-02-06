#include"ListNode.h"

int main()
{
	ListNode *Head=ListCreate();
	ListPushBack(Head, 1);
	ListPushBack(Head, 2);
	ListPushBack(Head, 3);
	ListPushBack(Head, 4);
	ListPopBack(Head);
	ListPushFront(Head, 0);
	ListPopFront(Head);
	ListInsert(Head->next->next, 5);
	ListErase(Head->next->next);
	ListPrint(Head);
	system("pause");
	return 0;
}