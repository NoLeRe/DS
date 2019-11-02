#include<stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool ismirror(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL&&q == NULL)
		return true;
	if (p == NULL || q == NULL)
		return false;
	if (p->val == q->val)
		return ismirror(p->left, q->right) && ismirror(p->right, q->left);
	else
		return false;
}

bool isSymmetric(struct TreeNode* root){

	return ismirror(root, root);
}