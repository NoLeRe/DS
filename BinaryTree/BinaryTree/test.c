#include"BinaryTree.h"

int main()
{
	char *a = "ABD##E#H##CF##G##";

	int pi = 0;
	BTNode* root=BinaryTreeCreate(a, &pi);
	// �������ڵ����
	printf("%d\n", BinaryTreeSize(root));
	// ������Ҷ�ӽڵ����
	printf("%d\n", BinaryTreeLeafSize(root));
	// ��������k��ڵ����
	printf("%d\n", BinaryTreeLevelKSize(root, 3));
	
	// ������ǰ�����
	BinaryTreePrevOrder(root);
	printf("\n");
	// ������������� 
	BinaryTreeInOrder(root);
	printf("\n");
	// �������������
	BinaryTreePostOrder(root);
	printf("\n");
	// �������
	BinaryTreeLevelOrder(root);
	printf("\n");
	// �ж϶������Ƿ�����ȫ������
	printf("%d\n", BinaryTreeComplete(root));
	system("pause");
	return 0;
}