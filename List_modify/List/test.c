#include"SList.h"

void test()
{
	ListNode* head = ListCreate();
	ListPushBack(head, 1);
	ListPushBack(head, 2);
	ListPushBack(head, 3);
	//ListPopBack(head);
	ListPushFront(head, 0);
	//ListPopFront(head);
	ListInsert( head, 10);
	ListErase(head->prev);
	ListPrint(head);
	//ListNode *data = ListFind(head, 1);
	//printf("%d ", data->data);
	//printf("%d ", data->next->data);

}

int main()
{
	test();
	system("pause");
	return 0;


}