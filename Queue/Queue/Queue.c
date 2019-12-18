#include"Queue.h"


// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->back = NULL;
}
// 队尾入队列
void QueuePush(Queue* q, DataType data)
{
	Node *node = (Node*)malloc(sizeof(Node));
	
	node->data = data;
	node->next = NULL;
	if (q->front == NULL)
	{
		q->front = node;
		q->back = node;
	}
	q->back->next = node;
	q->back = node;
	
}
// 队头出队列
void QueuePop(Queue* q)
{
	assert(q);
	Node *next = q->front->next;
	free(q->front);
	q->front = next;
}
// 获取队列头部元素
DataType QueueFront(Queue* q)
{
	assert(q);
	return q->front->data;
}
// 获取队列队尾元素
DataType QueueBack(Queue* q)
{
	assert(q);
	return q->back->data;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);
	int count = 0;
	Node* cur = q->front;
	while (cur)
	{
		cur = cur->next;
		count++;
	}
	return count;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	if (q->front == NULL)
		return 1;
	else
		return 0;

}
// 销毁队列
void QueueDestroy(Queue* q)
{
	
	while (q->front)
	{
		Node* next = q->front->next;
		free(q->front);
		q->front = next;
	}
}
//队列打印
void QueuePrint(Queue* q)
{
	Node *cur = q->front;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}




