
#include"SeqList.h"

void test()
{
	Seq ps;
	SeqListInit(&ps, 4);
	SeqListPushBack(&ps, 1);
	SeqListPushBack(&ps, 2);
	SeqListPushBack(&ps, 3);
	SeqListPushBack(&ps, 4);
	SeqListPushBack(&ps, 5);
	//SeqListPopBack(&ps);
	SeqListPushFront(&ps, 0);
	//SeqListPopFront(&ps);
	//SeqListFind(&ps, 2);
	SeqListInsert(&ps, 0, 6);
	SeqListPrint(&ps);
	printf("\n");
	//printf("%d", SeqListFind(&ps, 2));



}

int main()
{
	test();
	system("pause");
	return 0;
}