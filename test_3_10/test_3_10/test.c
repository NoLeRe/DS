#include<stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool issametree(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL&&q == NULL)
		return true;
	if (p == NULL || q == NULL)
		return false;
	if (p->val == q->val)
		return issametree(p->left, q->left) && issametree(p->right, q->right);
	else
		return false;
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){

	if (s == NULL&&t)
		return false;
	if (issametree(s, t))
		return true;
	else
		return isSubtree(s->left, t) || isSubtree(s->right, t);
}