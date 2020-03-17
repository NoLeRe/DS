#include<stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int countTreeNode(struct TreeNode* root)
{
	if (root == NULL)
		return 0;

	return 1 + countTreeNode(root->left) + countTreeNode(root->right);
}

void postorder(struct TreeNode* root, int *arr, int *i)
{
	if (root == NULL)
		return;

	postorder(root->left, arr, i);
	postorder(root->right, arr, i);
	arr[(*i)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){

	int k = countTreeNode(root);
	int *arr = (int*)malloc(sizeof(int)*k);
	int i = 0;
	postorder(root, arr, &i);

	*returnSize = k;
	return arr;

}