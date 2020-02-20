#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode ListNode;
int posnum(ListNode *head)
{
	int count = -1;
	ListNode *cur = head;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
int getDecimalValue(struct ListNode* head){

	int num = posnum(head);
	ListNode *cur = head;
	int count = 0;
	while (cur)
	{
		count = count + (cur->val)*pow(2, num);
		num--;
		cur = cur->next;
	}
	return count;
}

//int main(){
//	int arr[2][3] = { 1, 2, 3, 4, 5, 6 };    // ����һ����ά���鲢��ʼ��
//	int(*p)[3];                              // ����һ������ָ�룬ָ��ָ��һ������3��Ԫ�ص�һά����
//
//	p = arr;                                 // ����ά������׵�ַ���� p����ʱ p ָ�� arr[0] �� &arr[0][0]
//	printf("%d\n", (*p)[0]);				 // ������Ϊ 1
//	p++;									 // �� p �����������㣬��ʱ p ��ָ���ά�������һ�е��׵�ַ���� &arr[1][0]
//	printf("%d\n", (*p)[1]);                 // ������Ϊ5
//	system("pause");
//	return 0;
//}
void test(int** ptr)
{ 
	printf("num = %d\n", **ptr); 
}
int main()
{ 
	int n = 10;
	int*p = &n;
	int **pp = &p;
	test(pp);
	test(&p);
	system("pause");
	return 0;
}