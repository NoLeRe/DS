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
//	int arr[2][3] = { 1, 2, 3, 4, 5, 6 };    // 定义一个二维数组并初始化
//	int(*p)[3];                              // 定义一个数组指针，指针指向一个含有3个元素的一维数组
//
//	p = arr;                                 // 将二维数组的首地址赋给 p，此时 p 指向 arr[0] 或 &arr[0][0]
//	printf("%d\n", (*p)[0]);				 // 输出结果为 1
//	p++;									 // 对 p 进行算术运算，此时 p 将指向二维数组的下一行的首地址，即 &arr[1][0]
//	printf("%d\n", (*p)[1]);                 // 输出结果为5
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