#include<stdio.h>

/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *returnColumnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){

	//暴力求解法
	/*int end=target/2;
	int **a=(int**)malloc(sizeof(int*)*end);
	int row=0;

	for(int i=1;i<=end;i++)
	{
	int j=0;
	int kp=0;
	int sum=0;
	for(j=i;;j++)
	{
	sum+=j;
	kp++;
	if(sum>=target)
	break;
	}
	if(sum==target)
	{
	int col=0;

	a[row]=(int*)malloc(sizeof(int)*kp);
	for(int t=i;t<=j;t++)
	{
	a[row][col++]=t;
	}
	returnColumnSizes[0][row]=kp;
	row++;
	}
	}
	*returnSize=row;
	return a;
	*/

	//滑动窗口法
	int end = target / 2;
	int **a = (int**)malloc(sizeof(int*)*end);
	int i = 1, j = 2;
	int sum = 3;
	int row = 0;
	while (i <= end)
	{
		if (sum<target)
		{
			j++;
			sum += j;
		}
		else if (sum>target)
		{
			sum -= i;
			i++;
		}
		else
		{
			int col = 0;
			int count = j - i + 1;
			a[row] = (int*)malloc(sizeof(int)*count);
			for (int m = i; m <= j; m++)
			{
				a[row][col++] = m;
			}
			returnColumnSizes[0][row++] = count;
			sum -= i;
			i++;
		}
	}
	*returnSize = row;
	return a;

}