#pragma once


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#pragma warning (disable:4996)

typedef char DataType;
typedef struct BinaryTreeNode{

	DataType ch;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;

}BTNode;

typedef BTNode* QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode *next;
}Node;

typedef struct Queue
{
	Node *front;
	Node *back;
}Queue;

// ͨ��ǰ�����������"ABD##E#H##CF##G##"���������� 
BTNode* BinaryTreeCreate(DataType* a, int* pi);
// ����������
void BinaryTreeDestory(BTNode** root);
// �������ڵ����
int BinaryTreeSize(BTNode* root);
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root);
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);
// ����������ֵΪx�Ľڵ� 
BTNode* BinaryTreeFind(BTNode* root, DataType x);
// ������ǰ�����
void BinaryTreePrevOrder(BTNode* root);
// ������������� 
void BinaryTreeInOrder(BTNode* root);
// �������������
void BinaryTreePostOrder(BTNode* root);
// �������
void BinaryTreeLevelOrder(BTNode* root);
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root); 


void QueueInit(Queue* q);

void QueuePush(Queue* q, QDataType data);

void QueuePop(Queue* q);

void QueueDestroy(Queue* q);
