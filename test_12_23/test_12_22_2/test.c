#include<stdio.h>
#include<stdlib.h>
//循环队列
typedef struct {
	int *array;
	int front;
	int rear;
	int n;
} MyCircularQueue;
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);
/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue *q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	q->array = (int*)malloc(sizeof(int)*(k + 1));
	q->front = q->rear = 0;
	q->n = k + 1;
	return q;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(obj))
		return false;

	obj->array[obj->rear] = value;
	obj->rear++;
	if (obj->rear == obj->n)
		obj->rear = 0;

	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return false;
	obj->front++;
	if (obj->front == obj->n)
		obj->front = 0;

	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;

	return obj->array[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;
	int pre = obj->rear - 1;
	if (obj->rear == 0)
		pre = obj->n - 1;

	return obj->array[pre];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {

	return obj->front == obj->rear;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	int next = obj->rear + 1;
	next %= obj->n;

	return obj->front == next;
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->array);
	free(obj);
}

//环形列表返回表尾链接的节点
struct ListNode {
	int val;
	struct ListNode *next;
	
};
typedef struct ListNode ListNode;
struct ListNode *detectCycle(struct ListNode *head) {

	ListNode *fast = head;
	ListNode *slow = head;
	while (fast != NULL&&fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
		{
			fast = head;
			while (fast != slow)
			{
				fast = fast->next;
				slow = slow->next;
			}
			return fast;
		}
	}
	return NULL;
}