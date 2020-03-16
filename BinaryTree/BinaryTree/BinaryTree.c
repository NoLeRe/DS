#include "BinaryTree.h"

void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->back = NULL;
}
// ��β�����
void QueuePush(Queue* q, QDataType data)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	if (q->back == NULL)
	{
		q->front = q->back = node;
	}
	else
	{
		q->back->next = node;
		q->back = node;
	}

}
// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->front->data;
}
// ��ͷ������
void QueuePop(Queue* q)
{
	assert(q);
	if (q->front->next == NULL)
	{
		free(q->front);
		q->front = q->back = NULL;
	}
	else
	{
		Node *next = q->front->next;
		free(q->front);
		q->front = next;
	}
}


// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	if (q->front == NULL)
		return 1;
	else
		return 0;

}
// ���ٶ���
void QueueDestroy(Queue* q)
{
	assert(q);
	while (q->front)
	{
		Node* next = q->front->next;
		free(q->front);
		q->front = next;
	}
}

// ͨ��ǰ�����������"ABD##E#H##CF##G##"���������� 
BTNode* BinaryTreeCreate(DataType* a, int* pi)
{
	if (a[*pi] == '#')
		return NULL;
	else
	{
		BTNode *root = (BTNode*)malloc(sizeof(BTNode));
		root->ch = a[*pi];
		(*pi)++;
		root->left = BinaryTreeCreate(a, pi);
		(*pi)++;
		root->right = BinaryTreeCreate(a, pi);

		return root;
	}
}
// ����������
void BinaryTreeDestory(BTNode** root)
{
	if ((*root) && (*root)->left)
		BinaryTreeDestory(&(*root)->left);
	if ((*root) && (*root)->right)
		BinaryTreeDestory(&(*root)->right);

	free(root);
}
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL&&root->right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root&&k==1)
		return 1;
	if (root == NULL&&k == 1)
		return 0;
	k--;
	return BinaryTreeLevelKSize(root->left, k) + BinaryTreeLevelKSize(root->right,k);

}
// ����������ֵΪx�Ľڵ� 
BTNode* BinaryTreeFind(BTNode* root, DataType x)
{
	BTNode* ret = NULL;
	if (root == NULL)
		return NULL;
	if (root->ch == x)
		return root;
	ret = BinaryTreeFind(root->left, x);
	if (ret)
		return ret;
	ret = BinaryTreeFind(root->right, x);
	if (ret)
		return ret;
	return NULL;
}
// ������ǰ�����
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;

	printf("%c ", root->ch);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
// ������������� 
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->left);
	printf("%c ", root->ch);
	BinaryTreeInOrder(root->right);
}
// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->ch);
}
// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		printf("%c ", front->ch);
		if (front->left)
			QueuePush(&q, front->left);
		if (front->right)
			QueuePush(&q, front->right);
	}

	QueueDestroy(&q);

}
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root!=NULL)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
			break;		
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)
			return 0;
	}
	return 1;
}