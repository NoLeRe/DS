#include"BinaryTree.h"

int main()
{
	char *a = "ABD##E#H##CF##G##";

	int pi = 0;
	BTNode* root=BinaryTreeCreate(a, &pi);
	// 二叉树节点个数
	printf("%d\n", BinaryTreeSize(root));
	// 二叉树叶子节点个数
	printf("%d\n", BinaryTreeLeafSize(root));
	// 二叉树第k层节点个数
	printf("%d\n", BinaryTreeLevelKSize(root, 3));
	
	// 二叉树前序遍历
	BinaryTreePrevOrder(root);
	printf("\n");
	// 二叉树中序遍历 
	BinaryTreeInOrder(root);
	printf("\n");
	// 二叉树后序遍历
	BinaryTreePostOrder(root);
	printf("\n");
	// 层序遍历
	BinaryTreeLevelOrder(root);
	printf("\n");
	// 判断二叉树是否是完全二叉树
	printf("%d\n", BinaryTreeComplete(root));
	system("pause");
	return 0;
}