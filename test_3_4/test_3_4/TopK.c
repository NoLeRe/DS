#include"Heap.h"

void  printTopk(int *a, int k, int n)
{
	Heap hp;
	HeapCreate(&hp, a, k);
	for (int i = k; i <n; i++)
	{
		if (a[i]>HeapTop(&hp))
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}
	HeapPrint(&hp);
}
void testTopk()
{
	int a[1000] = { 0 };
	for (int i = 0; i < 1000; i++)
	{
		a[i] = rand() % 1000000;
	}
	/*a[15] = 1000000 + 1;
	a[101] = 1000000 + 2;
	a[185] = 1000000 + 3;
	a[98] = 1000000 + 4;
	a[584] = 1000000 + 5;
	a[154] = 1000000 + 6;
	a[784] = 1000000 + 7;
	a[879] = 1000000 + 8;
	a[135] = 1000000 + 9;
	a[365] = 1000000 + 10;*/
	printTopk(a, 10, 1000);

}
int main()
{
	testTopk();
	system("pause");
	return 0;
}