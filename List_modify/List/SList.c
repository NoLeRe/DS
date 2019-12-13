#include"SList.h"

// �������������ͷ���. 
ListNode* ListCreate()  
{
	ListNode *head = (ListNode*)malloc(sizeof(ListNode));
	head->data = NULL;
	head->next = head;
	head->prev = head;

	return head;
}

// ���ٿռ�
ListNode* BuyList(DataType x) 
{
	ListNode *node = (ListNode*)malloc(sizeof(ListNode));
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

// ˫���������� 
void ListDestory(ListNode* plist) 
{
	ListNode *cur = plist->next;
	while (cur != plist)
	{
		free(cur);
		cur = cur->next;
	}
	free(plist);
	plist = NULL;
}

// ˫�������ӡ
void ListPrint(ListNode* plist) 
{
	if (plist->next == plist)
	{
		printf("NULL\n");
	}
	ListNode *cur = plist->next;
	while (cur != plist)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
// ˫������β��
void ListPushBack(ListNode* plist, DataType x)
{
	ListNode *node = BuyList(x);
	ListNode *prev = plist->prev;
	prev->next = node;
	node->next = plist;
	node->prev = prev;
	plist->prev = node;
}

// ˫������βɾ
void ListPopBack(ListNode* plist)
{
	ListNode *tail = plist->prev;
	ListNode *prev = tail->prev;
	free(tail);
	tail = NULL;
	plist->prev = prev;
	prev->next = plist;
}

// ˫������ͷ��
void ListPushFront(ListNode* plist, DataType x)
{
	ListNode *node = BuyList(x);
	ListNode *first = plist->next;
	plist->next = node;
	node->next = first;
	first->prev = node;
	node->prev = plist;
}

// ˫������ͷɾ
void ListPopFront(ListNode* plist)
{
	assert(plist&&plist->next != plist);

	ListNode *first = plist->next;
	ListNode *second = plist->next->next;
	free(first);
	first = NULL;
	plist->next = second;
	second->prev = plist;

}

// ˫���������
ListNode* ListFind(ListNode* plist, DataType x)
{
	ListNode *cur = plist->next;
	while (cur->next != plist)
	{
		if (cur->data == x)
			return cur;
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, DataType x)
{
	ListNode *node = BuyList(x);
	ListNode *prev = pos->prev;
	prev->next = node;
	node->next = pos;
	node->prev = prev;
	pos->prev = node;
}

// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	ListNode *prev = pos->prev;
	ListNode *next = pos->next;
	free(pos);
	pos = NULL;
	prev->next = next;
	next->prev = prev;
}