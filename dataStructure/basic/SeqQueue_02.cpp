#include<iostream>
#define MaxSize 20
using namespace std;
typedef int ElemType; /* ElemType���͸���ʵ������������������Ϊint */

/*���ø������� size �ж϶������߶Կ�*/

/* ѭ�����е�˳��洢�ṹ */
typedef struct
{
	ElemType data[MaxSize];
	int front;    	/* ͷָ�� */
	int rear;		/* βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ�� */
	int size;    /* ���е�ǰ��С */
}SqQueue;

/*��ʼ������*/
bool InitQueue(SqQueue *Q)
{
	Q->front = Q->rear = 0;
	Q->size = 0;
	return true;
}

/*�ж϶����Ƿ�Ϊ��*/
bool QueueEmpty(SqQueue Q)
{
	if (Q.size == 0)
		return true;
	else
		return false;
}

/*�����*/
bool EnQueue(SqQueue *Q, ElemType x)
{
	if (Q->size == MaxSize)	/* ���������ж� */
		return false;
	Q->data[Q->rear] = x;
	Q->rear = (Q->rear + 1) % MaxSize; /* rearָ�������һλ�ã����������ת������ͷ�� */
	Q->size++;

	return  true;
}

/* �����в��գ���ɾ��Q�ж�ͷԪ��*/
bool DeQueue(SqQueue *Q, ElemType &x)
{
	if (Q->size == 0)			/* ���пյ��ж� */
		return false;
	x = Q->data[Q->front];
	Q->front = (Q->front + 1) % MaxSize;	/* frontָ�������һλ��,���������ת������ͷ�� */
	Q->size--;
	return true;
}

/*��ȡͷ��Ԫ��*/
bool GetHead(SqQueue Q, ElemType &x)
{
	if (Q.size == 0) /* ���п� */
		return false;
	x = Q.data[Q.front];
	return true;
}

/*���г���*/
int QueueLength(SqQueue Q)
{
	return  Q.size;
}

/* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ����� */
bool QueueTraverse(SqQueue Q)
{
	int i = Q.front;
	while (i %MaxSize != Q.rear)
	{
		cout << Q.data[i] << ' ';
		i++;
	}
	return true;
}

/* ��Q��Ϊ�ն��� */
bool ClearQueue(SqQueue *Q)
{
	Q->front = Q->rear = 0;
	Q->size = 0;
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

	for (int i = 1; i <= MaxSize; i++)
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