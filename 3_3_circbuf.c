#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct circbuf
{
	int * data;
	int cap;
	int count;
	int head;
	int tail;
};

void InitQueue(struct circbuf * q, int nel)
{
	q->cap = nel;
	q->data = (int *)malloc(sizeof(int) * nel);
	q->count = 0;
	q->head = 0;
	q->tail = 0;
}

int QueueEmpty(struct circbuf * q)
{
	return q->count;
}

void Enqueue(struct circbuf * q, long int x)
{
	q->data[q->tail] = x;
	q->tail++;
	if(q->tail == q->cap)
	{
		q->tail = 0;
	}
	q->count++;
}	

int Dequeue(struct circbuf * q)
{
	if(QueueEmpty(q) == 0)
	{
		printf("Error");
		return 0;
	}
	int x =  q->data[q->head];
	q->head++;
	if(q->head == q->cap)
	{
		q->head = 0;
	}
	q->count--;
	return x;
}

void REALLOC(struct circbuf * q, int nel)
{
	q->cap = nel;
	q->data = (int *)realloc(q->data, (sizeof(int) * nel));
	memcpy(q->data + (q->cap / 2), q->data, sizeof(int) * (q->cap /2));
	q->tail = (q->cap/ 2) + q->tail;
}

int main(void)
{
	struct circbuf q;
	int nel = 4;
	InitQueue(&q, nel);
	int n;
	scanf("%d", &n);
	int i = 0;
	char str[5];
	int x = 0;
	for(i = 0; i < n; i++)
	{
		scanf("%s", str);
		switch(str[0])
		{
			case 'E':
			{
				if(str[1] == 'N')
				{
					scanf("%d", &x);
					if(q.count == q.cap)
					{
						nel *=2;
						REALLOC(&q, nel);
					}
					Enqueue(&q, x);
					
				}
				else
				{
					if(QueueEmpty(&q) == 0)
					{
						printf("true \n");
					}
					else
					{
						printf("false \n");
					}
				}
				break;
			}
			case 'D':
			{
				printf("%d \n", Dequeue(&q));
				break;
			}
			default :
			{
				printf("ERROR");
				return 1;
			}
		}
	}
	free(q.data);
	return 0;
}
