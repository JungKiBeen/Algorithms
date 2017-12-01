#define Q_SIZE 10000

#include <Windows.h>

CRITICAL_SECTION cs_que;


typedef int data; // ms 

typedef struct queue {
	int head;
	int tail;
	int cnt;
	data ar[Q_SIZE];
}QUEUE;

void enqueue(QUEUE *q, data x);
data dequeue(QUEUE *q);
int queue_empty(QUEUE* q);
int queue_full(QUEUE* q);
int get_qcnt(QUEUE* q)


///////////////////////////////////////////////

int get_qcnt(QUEUE* q)
{
	EnterCriticalSection(&cs_que);           // lock È¹µæ È¤Àº waiting
	int ret = q->cnt;
	LeaveCriticalSection(&cs_que);           // lock ¹ÝÈ¯

	return ret;
}

int queue_full(QUEUE* q)
{
	EnterCriticalSection(&cs_que);           // lock È¹µæ È¤Àº waiting
	int ret = ((q->head + 1) % Q_SIZE == q->tail);
	LeaveCriticalSection(&cs_que);           // lock ¹ÝÈ¯

	return ret;
}


int queue_empty(QUEUE* q)
{
	EnterCriticalSection(&cs_que);           // lock È¹µæ È¤Àº waiting
	int ret = (q->head == q->tail);
	LeaveCriticalSection(&cs_que);           // lock ¹ÝÈ¯

	return ret;
}


void enqueue(QUEUE *q, data x)
{
	EnterCriticalSection(&cs_que);           // lock È¹µæ È¤Àº waiting

	if ((q->head + 1) % Q_SIZE == q->tail)
	{
		printf("the queue is full!\n");

		return;
	}

	q->head = (q->head + 1) % Q_SIZE;

	q->ar[q->head] = x;
	q->cnt++;
	LeaveCriticalSection(&cs_que);           // lock ¹ÝÈ¯

}


data dequeue(QUEUE *q)
{
	EnterCriticalSection(&cs_que);           // lock È¹µæ È¤Àº waiting
	data ret;

	if (q->head == q->tail)
	{
		printf("the queue is empty!\n");
		return 0;
	}

	q->tail = (q->tail + 1) % Q_SIZE;
	ret = q->ar[q->tail];
	q->cnt--;
	LeaveCriticalSection(&cs_que);           // lock ¹ÝÈ¯

	return ret;
}