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

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树 
BTNode* BinaryTreeCreate(DataType* a, int* pi);
// 二叉树销毁
void BinaryTreeDestory(BTNode** root);
// 二叉树节点个数
int BinaryTreeSize(BTNode* root);
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root);
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);
// 二叉树查找值为x的节点 
BTNode* BinaryTreeFind(BTNode* root, DataType x);
// 二叉树前序遍历
void BinaryTreePrevOrder(BTNode* root);
// 二叉树中序遍历 
void BinaryTreeInOrder(BTNode* root);
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root);
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root); 


void QueueInit(Queue* q);

void QueuePush(Queue* q, QDataType data);

void QueuePop(Queue* q);

void QueueDestroy(Queue* q);
