#include<stdio.h>

//≤Â»Î≈≈–Ú
void InsertSort(int *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int temp = a[end + 1];
		while (end >= 0)
		{
			if (a[end]>temp)
				a[end + 1] = a[end];
			else
				break;
			end--;
		}
		a[end + 1] = temp;
	}
}

//œ£∂˚≈≈–Ú

void ShellSort(int *a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int temp = a[end + gap];
			while (end >= 0)
			{
				if (a[end]>temp)
					a[end + gap] = a[end];
				else
					break;
				end-=gap;
			}
			a[end + gap] = temp;
		}
	}
}

//—°‘Ò≈≈–Ú
void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
 
void SelectSort(int *a, int n)
{
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		int mini = start;
		int maxi = end;
		for (int i = start; i <= end; i++)
		{
			if (a[i]>a[maxi])
				maxi = i;
			if (a[i] < a[mini])
				mini = i;
		}
		swap(&a[start], &a[mini]);
		if (start == maxi)
			maxi = mini;
		swap(&a[end], &a[maxi]);
		start++;
		end--;
	}
	
}

//∂—≈≈–Ú
void AdustDown(int *a, int root, int n)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n&&a[child] < a[child + 1])
			child++;
		if (a[parent] < a[child])
		{
			swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapSort(int *a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdustDown(a, i, n);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		swap(&a[0], &a[i]);
		AdustDown(a, 0, i);
	}
}


void testInsertSort(int *a,int n)
{
	InsertSort(a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void testShelltSort(int *a, int n)
{
	ShellSort(a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void testSelectSort(int *a, int n)
{
	SelectSort(a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void testHeapSort(int *a, int n)
{
	HeapSort(a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int a[10] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	int n = 10;
	//testInsertSort(a, n);
	//testShelltSort(a, n);
	testSelectSort(a, n);
	//testHeapSort(a, n);
	system("pause");
	return 0;
}
