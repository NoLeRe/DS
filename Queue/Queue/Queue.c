#include"Queue.h"


// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->back = NULL;
}
// ��β�����
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
// ��ͷ������
void QueuePop(Queue* q)
{
	assert(q);
	Node *next = q->front->next;
	free(q->front);
	q->front = next;
}
// ��ȡ����ͷ��Ԫ��
DataType QueueFront(Queue* q)
{
	assert(q);
	return q->front->data;
}
// ��ȡ���ж�βԪ��
DataType QueueBack(Queue* q)
{
	assert(q);
	return q->back->data;
}
// ��ȡ��������ЧԪ�ظ��� 
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
	
	while (q->front)
	{
		Node* next = q->front->next;
		free(q->front);
		q->front = next;
	}
}
//���д�ӡ
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




