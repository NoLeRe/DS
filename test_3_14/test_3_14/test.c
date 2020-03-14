#include<stdio.h>
#include<malloc.h>

typedef struct BinaryTree{
	char ch;
	struct BinaryTree *left;
	struct BinaryTree *right;
}Tree;

Tree* ReBuild(char *a, int *i)
{
	if (a[*i] == '#')
		return NULL;
	Tree* root = (Tree*)malloc(sizeof(Tree));
	root->ch = a[*i];
	(*i)++;
	root->left = ReBuild(a, i);
	(*i)++;
	root->right = ReBuild(a, i);

	return root;
}
void InOrder(Tree* root)
{
	if (root == NULL)
		return;
	InOrder(root->left);
	printf("%c ", root->ch);
	InOrder(root->right);
}

int main()
{
	char a[100];
	scanf("%s", a);
	int i = 0;
	Tree *root = ReBuild(a, &i);
	InOrder(root);
	return 0;
}