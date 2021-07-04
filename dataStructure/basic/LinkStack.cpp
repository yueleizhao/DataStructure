#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int ElemType; /* ElemType类型根据实际情况而定，这里假设为int */

/* 链栈结构 */
typedef struct LinkNode
{
	ElemType data;
	struct LinkNode *next;
}LinkNode, *LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;
	int count;  /*如果频繁需要知道栈的大小，可设头结点*/
}LinkStack;


/*初始化栈*/
bool InitLinkStack(LinkStack *head)
{
	head->top = (LinkStackPtr)malloc(sizeof(LinkNode));
	if (!head->top)
		return false;
	head->top = NULL;
	head->count = 0;
	return true;
}

/*头插法，进栈*/
bool Push(LinkStack *head, ElemType x)
{
	LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL)/*内存分配失败*/
		return false;
	s->data = x;
	s->next = head->top;
	head->top = s;
	head->count++;
	return true;
}

/* 判断栈是否为空*/
bool StackEmpty(LinkStack head)
{
	if (head.count == 0)
		return true;
	else
		return false;
}

/* 若栈不空，删除头结点后的结点 */
bool Pop(LinkStack *head, ElemType &x)
{
	LinkNode *temp;
	if (StackEmpty(*head))//栈为空
		return false;

	x = head->top->data;
	temp = head->top;
	head->top = head->top->next;
	free(temp);
	head->count--;
	return true;
}

/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
bool GetTop(LinkStack *head, ElemType &x)
{
	if (head->top == NULL)
		return false;
	else
		x = head->top->data;
	return true;
}

/*输出栈内元素*/
bool StackTraverse(LinkStack head)
{
	LinkNode *p = head.top;
	if (!p)
		return false;
	while (p)
	{
		cout << p->data;
		p = p->next;
	}
	return true;
}

/*返回栈的大小*/
int StackSize(LinkStack head)
{
	return head.count;
}

/*销毁栈*/
void DestroyStack(LinkStack *head)
{
	LinkStackPtr  p = head->top, temp;

	while (p)
	{
		temp = p;
		p = p->next;
		free(temp);
	}
	head->count = 0;
}

int main()
{
	int cnt = 0;
	LinkStack head;
	if (InitLinkStack(&head))
	{
		cout << "创建链栈成功！" << "\n";
		for (int i = 1; i <= 10; i++)
			Push(&head, i);
	}
	else
	{
		cout << "创建链栈失败！" << "\n";
	}

	if (Pop(&head, cnt))
	{
		cout << "弹出栈顶元素：" << cnt << "\n";
	}

	cout << "栈的大小：" << StackSize(head) << "\n";

	if (GetTop(&head, cnt))
	{
		cout << "栈顶元素：" << cnt << "\n";
	}
	if (StackEmpty(head))
	{
		cout << "栈为空！" << "\n";
	}
	else
	{
		cout << "栈非空！" << "\n";
	}

	StackTraverse(head);

	DestroyStack(&head);

	return 0;
}