#include<iostream>
#define MaxSize 20
using namespace std;
typedef int ElemType; /* ElemType���͸���ʵ������������������Ϊint */

/* ѭ�����е�˳��洢�ṹ */
typedef struct
{
	ElemType data[MaxSize];
	int front;    	/* ͷָ�� */
	int rear;		/* βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ�� */
}SqQueue;

/*��ʼ������*/
bool InitQueue(SqQueue *Q)
{
	Q->front = Q->rear = 0;
	return true;
}

/*�ж϶����Ƿ�Ϊ��*/
bool QueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)/* ���пյı�־ */
		return true;
	else
		return false;
}

/*�����*/
bool EnQueue(SqQueue *Q, ElemType x)
{
	if ((Q->rear + 1) % MaxSize == Q->front)	/* ���������ж� */
		return false;
	Q->data[Q->rear] = x;
	Q->rear = (Q->rear + 1) % MaxSize; /* rearָ�������һλ�ã����������ת������ͷ�� */
	return  true;
}

/* �����в��գ���ɾ��Q�ж�ͷԪ��*/
bool DeQueue(SqQueue *Q, ElemType &x)
{
	if (Q->front == Q->rear)			/* ���пյ��ж� */
		return false;
	x = Q->data[Q->front];
	Q->front = (Q->front + 1) % MaxSize;	/* frontָ�������һλ��,���������ת������ͷ�� */

	return true;
}

/*��ȡͷ��Ԫ��*/
bool GetHead(SqQueue Q, ElemType &x)
{
	if (Q.front == Q.rear) /* ���п� */
		return false;
	x = Q.data[Q.front];
	return true;
}

/*���г���*/
int QueueLength(SqQueue Q)
{
	return  (Q.rear - Q.front + MaxSize) % MaxSize;
}

/* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ����� */
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

/* ��Q��Ϊ�ն��� */
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
		cout << "��ʼ���󣬶���Ϊ��!" << "\n";
	}

	for (int i = 1; i <= MaxSize - 1; i++)
	{
		EnQueue(&Q, i);
	}

	cout << "���г���:" << QueueLength(Q) << "\n";

	QueueTraverse(Q);

	cout << "\n" << "ɾ��Ԫ��:";

	for (int i = 0; i < MaxSize - 2; i++)
	{
		DeQueue(&Q, cnt);
		cout << cnt;
	}

	cout << "\n" << "���ڶ����е�Ԫ��:";

	QueueTraverse(Q);

	cout << "\n";

	GetHead(Q, cnt);

	cout << cnt;
	return 0;
}