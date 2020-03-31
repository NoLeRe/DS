#include<stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

int Depth(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	int leftDepth = 1 + Depth(root->left);
	int rightDepth = 1 + Depth(root->right);

	return (leftDepth>rightDepth ? leftDepth : rightDepth);
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
	if (root == NULL)
	{
		*returnSize = 0;
		return NULL;
	}

	int row = Depth(root);
	int **a = (int**)malloc(sizeof(int*)*row);

	int arr[1000][500];
	int p2 = 0;
	int p1 = 0;
	int col[1000];
	int curnum = 0;
	int nextnum = 0;


	Queue  q;
	QueueInit(&q);
	returnColumnSizes[0] = (int*)malloc(sizeof(int)*row);
	QueuePush(&q, root);
	col[p1++] = 1;
	curnum++;

	while (!QueueEmpty(&q))
	{
		if (curnum == 0)
		{
			curnum = nextnum;
			nextnum = 0;
			col[p1++] = curnum;
			p2 = 0;
		}
		TreeNode* front = QueueFront(&q);
		arr[p1 - 1][p2++] = front->val;
		QueuePop(&q);
		curnum--;

		if (front->left)
		{
			QueuePush(&q, front->left);
			nextnum++;
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
			nextnum++;
		}
	}
	memcpy(*returnColumnSizes, col, row * sizeof(int));
	for (int i = 0; i < row; i++)
	{
		a[i] = (int*)malloc(returnColumnSizes[0][i] * sizeof(int));
		memcpy(a[i], arr[i], returnColumnSizes[0][i] * sizeof(int));
	}

	*returnSize = row;
	return a;
}