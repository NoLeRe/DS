#include<stdio.h>
#include<stdlib.h>

typedef int DataType;

typedef struct ListNode{
	DataType val;
	struct ListNode *prev;
	struct ListNode *next;
}ListNode;

// �������������ͷ���
ListNode* ListCreate();
// ˫����������
void ListDestory(ListNode* plist);
// ˫�������ӡ
void ListPrint(ListNode* plist);
// ˫������β��
void ListPushBack(ListNode* plist, DataType x);
// ˫������βɾ
void ListPopBack(ListNode* plist);
// ˫������ͷ��
void ListPushFront(ListNode* plist, DataType x);
// ˫������ͷɾ
void ListPopFront(ListNode* plist);
// ˫���������
ListNode* ListFind(ListNode* plist, DataType x);
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, DataType x);
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos); 
//���ٿռ�
ListNode* BuyList(DataType x);