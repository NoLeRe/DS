#include<stdio.h>

typedef struct Node{
	int val;
	struct Node *next;

} MyLinkedList;

int NodeCount(MyLinkedList *obj)
{
	MyLinkedList *cur = obj;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {

	MyLinkedList *ls = (MyLinkedList*)malloc(sizeof(MyLinkedList));
	ls->next = NULL;
	return ls;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {

	if (index<0)
		return -1;
	MyLinkedList *cur = obj;
	index++;
	while (index--)
	{
		cur = cur->next;
		if (cur == NULL)
			return -1;
	}

	return cur->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {

	MyLinkedList *Node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
	Node->val = val;
	MyLinkedList *next = obj->next;
	obj->next = Node;
	Node->next = next;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {


	MyLinkedList *Node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
	Node->val = val;
	MyLinkedList *tail = obj;
	while (tail->next)
	{
		tail = tail->next;
	}
	tail->next = Node;
	Node->next = NULL;

}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {


	MyLinkedList *cur = obj->next;
	if (index == NodeCount(obj))
		myLinkedListAddAtTail(obj, val);
	else if (index <= 0)
		myLinkedListAddAtHead(obj, val);
	else
	{

		MyLinkedList *pre = NULL;
		while (index--)
		{
			pre = cur;
			cur = cur->next;
		}
		MyLinkedList *Node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
		Node->val = val;
		pre->next = Node;
		Node->next = cur;
	}

}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {

	if (index<0)
		return;

	MyLinkedList *cur = obj->next;
	MyLinkedList *pre = obj;
	while (index--)
	{
		pre = cur;
		cur = cur->next;
		if (cur == NULL)
			return;
	}
	MyLinkedList *next = cur->next;
	free(cur);
	pre->next = next;

}

void myLinkedListFree(MyLinkedList* obj) {
	MyLinkedList *next = obj;
	while (obj)
	{
		next = obj->next;
		free(obj);
		obj = next;
	}

}