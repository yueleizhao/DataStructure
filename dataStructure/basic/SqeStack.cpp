#include<iostream>
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */
using namespace std;
typedef int ElemType; /* SElemType���͸���ʵ������������������Ϊint */

typedef struct
{
	ElemType data[MAXSIZE] = { 0 };
	int top; /* ����ջ��ָ�� ,ָ��ջ��Ԫ��*/
}SqStack;

/*��ʼ��ջ*/
void InitStack(SqStack &s)
{
	s.top = -1;
}

/*�ж�ջ�Ƿ�Ϊ��*/
bool StackEmpty(SqStack s)
{
	if (s.top == -1)
		return true;
	else
		return false;
}

/*��ջ*/
bool Push(SqStack &s, ElemType x)
{
	if (s.top == MAXSIZE - 1)
		return false;
	s.data[++s.top] = x;
	return true;
}

/*��ȡջ��Ԫ�أ����ҳ�ջ*/
bool Pop(SqStack &s, ElemType&x)
{
	if (s.top == -1)
		return false;
	x = s.data[s.top--];
	return true;
}

/*��ȡջ��Ԫ��*/
bool GetTop(SqStack &s, ElemType&x)
{
	if (s.top == -1)
		return false;
	x = s.data[s.top];
	return true;
}

/*ջ��ʵ�ʴ�С*/
int StackLength(SqStack &s)
{
	return s.top + 1;
}

/*��ջ�͵�ջ�����*/
bool StackTraverse(SqStack &s)
{
	if (s.top == -1)
		return false;
	int i = 0;
	while (i <= s.top)
	{
		cout << s.data[i++];
	}
	cout << "\n";
	return true;
}

/*����ջ*/
void DestroyStack(SqStack &s)
{
	s.top = -1;
}

int main()
{
	SqStack s;
	int cnt = 0;
	InitStack(s);
	for (int i = 1; i <= 10; i++)
		Push(s, i);

	cout << "ջ�е�Ԫ��Ϊ��" << "\n";
	StackTraverse(s);

	if (Pop(s, cnt))
		cout << "����ջ��Ԫ��:" << cnt << "\n";

	if (StackEmpty(s))
		cout << "ջΪ��" << "\n";
	else
		cout << "ջ�ǿ�" << "\n";

	cout << "ջ�Ĵ�С��" << StackLength(s) << "\n";

	if (GetTop(s, cnt))
		cout << "ջ��Ԫ�أ�" << cnt << "\n";

	DestroyStack(s);

	if (StackEmpty(s))
		cout << "ջΪ��" << "\n";
	else
		cout << "ջ�ǿ�" << "\n";

	return 0;
}