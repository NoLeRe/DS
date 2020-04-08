#include<stdio.h>
typedef struct {
	int *a;
	int *b;
	int top;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {

	MinStack* st = (MinStack*)malloc(sizeof(MinStack));
	st->a = (int*)malloc(sizeof(int)* 20000);
	st->b = (int*)malloc(sizeof(int)* 20000);
	st->top = 0;

	return st;
}

void minStackPush(MinStack* obj, int x) {
	if (obj->top == 0)
	{
		obj->a[obj->top] = x;
		obj->b[obj->top] = x;
	}
	else
	{
		obj->a[obj->top] = x;
		obj->b[obj->top] = obj->b[obj->top - 1]>x ? x : obj->b[obj->top - 1];

	}
	obj->top++;
}

void minStackPop(MinStack* obj) {

	obj->top--;
}

int minStackTop(MinStack* obj) {

	return obj->a[obj->top - 1];
}

int minStackMin(MinStack* obj) {

	return obj->b[obj->top - 1];
}

void minStackFree(MinStack* obj) {

	free(obj->a);
	obj->a = NULL;
	obj->top = 0;
	free(obj);
}

/**
* Your MinStack struct will be instantiated and called as such:
* MinStack* obj = minStackCreate();
* minStackPush(obj, x);

* minStackPop(obj);

* int param_3 = minStackTop(obj);

* int param_4 = minStackMin(obj);

* minStackFree(obj);
*/