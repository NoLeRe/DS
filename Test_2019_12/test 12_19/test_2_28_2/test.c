#include<stdio.h>

void AdjustDown(int *a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;

	while (child < n)
	{
		if (child + 1 < n&&child > child + 1)
			child++;
		if (a[parent]>a[child])
		{
			int tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;

			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void AdjustUp(int *a, int child)
{
	int parent = (child - 1) / 2;
	while (child)
	{
		if (a[parent]>a[child])
		{
			int temp = a[parent];
			a[parent] = a[child];
			a[child] = temp;
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}