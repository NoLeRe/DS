#include<stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int numberTree(struct TreeNode* root)
{
	if (root == NULL)
		return 0;

	return 1 + numberTree(root->left) + numberTree(root->right);
}
void pretravel(struct TreeNode* root, int *arr, int* i)
{
	if (root == NULL)
		return;
	arr[(*i)++] = root->val;
	pretravel(root->left, arr, i);
	pretravel(root->right, arr, i);

}
int* preorderTraversal(struct TreeNode* root, int* returnSize){

	int n = numberTree(root);
	int *arr = (int*)malloc(sizeof(int)*n);
	int i = 0;
	pretravel(root, arr, &i);
	*returnSize = n;
	return arr;

}