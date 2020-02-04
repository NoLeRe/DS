#include"seq.h"


int main()
{
	seq q;
	SeqListInit(&q, 20);
	SeqListPushBack(&q, 1);
	SeqListPushBack(&q, 2);
	SeqListPushBack(&q, 3);
	SeqListPushBack(&q, 4);
	SeqListPrint(&q);
	SeqListPushFront(&q, 0);
	//SeqListPopFront(&q);
	//SeqListPrint(&q);
	//SeqListInsert(&q, 3, 5);
	SeqListDestory(&q);
	SeqListPrint(&q);

	printf("%d \n", SeqListFind(&q, 2));

	system("pause");
	return 0;
}