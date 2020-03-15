#include<stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
typedef struct TreeNode TreeNode;

int countTreeNode(struct TreeNode* root)
{
	if (root == NULL)
		return 0;

	return 1 + countTreeNode(root->left) + countTreeNode(root->right);
}

void inorder(struct TreeNode* root, int *arr, int *i)
{
	if (root == NULL)
		return;
	inorder(root->left, arr, i);
	arr[(*i)++] = root->val;
	inorder(root->right, arr, i);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){

	int k = countTreeNode(root);
	int *arr = (int*)malloc(sizeof(int)*k);
	int i = 0;
	inorder(root, arr, &i);

	*returnSize = k;
	return arr;

}