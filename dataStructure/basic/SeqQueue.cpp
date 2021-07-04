#include<iostream>
#define MaxSize 20
using namespace std;
typedef int ElemType; /* ElemType类型根据实际情况而定，这里假设为int */

/* 循环队列的顺序存储结构 */
typedef struct
{
	ElemType data[MaxSize];
	int front;    	/* 头指针 */
	int rear;		/* 尾指针，若队列不空，指向队列尾元素的下一个位置 */
}SqQueue;

/*初始化队列*/
bool InitQueue(SqQueue *Q)
{
	Q->front = Q->rear = 0;
	return true;
}

/*判断队列是否为空*/
bool QueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)/* 队列空的标志 */
		return true;
	else
		return false;
}

/*入队列*/
bool EnQueue(SqQueue *Q, ElemType x)
{
	if ((Q->rear + 1) % MaxSize == Q->front)	/* 队列满的判断 */
		return false;
	Q->data[Q->rear] = x;
	Q->rear = (Q->rear + 1) % MaxSize; /* rear指针向后移一位置，若到最后则转到数组头部 */
	return  true;
}

/* 若队列不空，则删除Q中队头元素*/
bool DeQueue(SqQueue *Q, ElemType &x)
{
	if (Q->front == Q->rear)			/* 队列空的判断 */
		return false;
	x = Q->data[Q->front];
	Q->front = (Q->front + 1) % MaxSize;	/* front指针向后移一位置,若到最后则转到数组头部 */

	return true;
}

/*获取头部元素*/
bool GetHead(SqQueue Q, ElemType &x)
{
	if (Q.front == Q.rear) /* 队列空 */
		return false;
	x = Q.data[Q.front];
	return true;
}

/*队列长度*/
int QueueLength(SqQueue Q)
{
	return  (Q.rear - Q.front + MaxSize) % MaxSize;
}

/* 从队头到队尾依次对队列Q中每个元素输出 */
bool QueueTraverse(SqQueue Q)
{
	int i = 0;
	while (((i + Q.front) % MaxSize) != Q.rear)
	{
		cout << Q.data[i];
		i++;
	}
	return true;
}

/* 将Q清为空队列 */
bool ClearQueue(SqQueue *Q)
{
	Q->front = Q->rear = 0;
	return true;
}

int main()
{
	int cnt = 0;
	SqQueue Q;
	InitQueue(&Q);
	if (QueueEmpty(Q))
	{
		cout << "初始化后，队列为空!" << "\n";
	}

	for (int i = 1; i <= MaxSize - 1; i++)
	{
		EnQueue(&Q, i);
	}

	cout << "队列长度:" << QueueLength(Q) << "\n";

	QueueTraverse(Q);

	cout << "\n" << "删除元素:";

	for (int i = 0; i < MaxSize - 2; i++)
	{
		DeQueue(&Q, cnt);
		cout << cnt;
	}

	cout << "\n" << "现在队列中的元素:";

	QueueTraverse(Q);

	cout << "\n";

	GetHead(Q, cnt);

	cout << cnt;
	return 0;
}