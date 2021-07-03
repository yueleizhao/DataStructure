#include<iostream>
#define MAXSIZE 20 /* 存储空间初始分配量 */
using namespace std;
typedef int ElemType; /* SElemType类型根据实际情况而定，这里假设为int */

typedef struct
{
	ElemType data[MAXSIZE] = { 0 };
	int top; /* 用于栈顶指针 ,指向栈顶元素*/
}SqStack;

/*初始化栈*/
void InitStack(SqStack &s)
{
	s.top = -1;
}

/*判断栈是否为空*/
bool StackEmpty(SqStack s)
{
	if (s.top == -1)
		return true;
	else
		return false;
}

/*入栈*/
bool Push(SqStack &s, ElemType x)
{
	if (s.top == MAXSIZE - 1)
		return false;
	s.data[++s.top] = x;
	return true;
}

/*获取栈顶元素，并且出栈*/
bool Pop(SqStack &s, ElemType&x)
{
	if (s.top == -1)
		return false;
	x = s.data[s.top--];
	return true;
}

/*获取栈顶元素*/
bool GetTop(SqStack &s, ElemType&x)
{
	if (s.top == -1)
		return false;
	x = s.data[s.top];
	return true;
}

/*栈的实际大小*/
int StackLength(SqStack &s)
{
	return s.top + 1;
}

/*从栈低到栈顶输出*/
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

/*销毁栈*/
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

	cout << "栈中的元素为：" << "\n";
	StackTraverse(s);

	if (Pop(s, cnt))
		cout << "弹出栈顶元素:" << cnt << "\n";

	if (StackEmpty(s))
		cout << "栈为空" << "\n";
	else
		cout << "栈非空" << "\n";

	cout << "栈的大小：" << StackLength(s) << "\n";

	if (GetTop(s, cnt))
		cout << "栈顶元素：" << cnt << "\n";

	DestroyStack(s);

	if (StackEmpty(s))
		cout << "栈为空" << "\n";
	else
		cout << "栈非空" << "\n";

	return 0;
}