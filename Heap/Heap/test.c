#include"Heap.h"

int main()
{
	int a[10] = { 65, 18, 19, 28, 27, 31, 25, 34, 49, 15 };
	Heap hp;
	HeapCreate(&hp, a, 10);
	HeapPrint(&hp);
	HeapPush(&hp, 9);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);


	system("pause");
	return 0;
}