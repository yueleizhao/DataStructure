#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int ElemType; /* ElemType���͸���ʵ������������������Ϊint */

/* ��ջ�ṹ */
typedef struct LinkNode
{
	ElemType data;
	struct LinkNode *next;
}LinkNode, *LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;
	int count;  /*���Ƶ����Ҫ֪��ջ�Ĵ�С������ͷ���*/
}LinkStack;


/*��ʼ��ջ*/
bool InitLinkStack(LinkStack *head)
{
	head->top = (LinkStackPtr)malloc(sizeof(LinkNode));
	if (!head->top)
		return false;
	head->top = NULL;
	head->count = 0;
	return true;
}

/*ͷ�巨����ջ*/
bool Push(LinkStack *head, ElemType x)
{
	LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL)/*�ڴ����ʧ��*/
		return false;
	s->data = x;
	s->next = head->top;
	head->top = s;
	head->count++;
	return true;
}

/* �ж�ջ�Ƿ�Ϊ��*/
bool StackEmpty(LinkStack head)
{
	if (head.count == 0)
		return true;
	else
		return false;
}

/* ��ջ���գ�ɾ��ͷ����Ľ�� */
bool Pop(LinkStack *head, ElemType &x)
{
	LinkNode *temp;
	if (StackEmpty(*head))//ջΪ��
		return false;

	x = head->top->data;
	temp = head->top;
	head->top = head->top->next;
	free(temp);
	head->count--;
	return true;
}

/* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
bool GetTop(LinkStack *head, ElemType &x)
{
	if (head->top == NULL)
		return false;
	else
		x = head->top->data;
	return true;
}

/*���ջ��Ԫ��*/
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

/*����ջ�Ĵ�С*/
int StackSize(LinkStack head)
{
	return head.count;
}

/*����ջ*/
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
		cout << "������ջ�ɹ���" << "\n";
		for (int i = 1; i <= 10; i++)
			Push(&head, i);
	}
	else
	{
		cout << "������ջʧ�ܣ�" << "\n";
	}

	if (Pop(&head, cnt))
	{
		cout << "����ջ��Ԫ�أ�" << cnt << "\n";
	}

	cout << "ջ�Ĵ�С��" << StackSize(head) << "\n";

	if (GetTop(&head, cnt))
	{
		cout << "ջ��Ԫ�أ�" << cnt << "\n";
	}
	if (StackEmpty(head))
	{
		cout << "ջΪ�գ�" << "\n";
	}
	else
	{
		cout << "ջ�ǿգ�" << "\n";
	}

	StackTraverse(head);

	DestroyStack(&head);

	return 0;
}