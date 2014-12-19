#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct circbuf
{
	int * data;
	int cap;
	int top1;
	int top2;
	int max;
};

void InitDoubleStack(struct circbuf * q, int nel)
{
	q->cap = nel;
	q->data = (int *)malloc(sizeof(int) * nel);
	q->top1 = 0;
	q->top2 = nel-1;
	q->max = -2000000000;
}

int StackEmpty1(struct circbuf * q)
{
	if(q->top1 == 0)
	{
		return 1;
	} 
	else
	{
		return 0;
	}
}

int StackEmpty2(struct circbuf * q)
{
	if(q->top2 == q->cap - 1)
	{
		return 1;
	} 
	else
	{
		return 0;
	}
}

int QueueEmpty(struct circbuf * q)
{
	if(StackEmpty1(q) == 1 &&  StackEmpty2(q) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}


void Max(struct circbuf * q, int x)
{
	if(x > q->max)
	{
		q->max = x;
	}
}

void Push2(struct circbuf * q, int x)
{
	if(q->top2 < q->top1)
	{
		return;
	}
	q->data[q->top2] = x;
	q->top2--;
	Max(q, x);
}

void Push1(struct circbuf * q, int x)
{
	if(q->top2 < q->top1)
	{
		return;
	}
	q->data[q->top1] = x;
	q->top1++;
	Max(q, x);
}

int Pop2(struct circbuf * q)
{
	q->top2++;
	return q->data[q->top2];

}

int Pop1(struct circbuf * q)
{
	q->top1--;
	return q->data[q->top1];

}
void NEWMAX(struct circbuf * q)
{
	int i = 0;
	for(i = q->top2+1; i < q->cap; i++)
	{
		if(q->max < q->data[i])
		{
			q->max = q->data[i];
		}
	}
	for(i = 0; i < q->top1; i++)
	{
		if(q->max < q->data[i])
		{
			q->max = q->data[i];
		}
	}
}

void Enqueue(struct circbuf * q, int x)
{
	Push1(q, x);
}	

int Dequeue(struct circbuf * q)
{
	if(StackEmpty2(q) == 1)
	{
		while(StackEmpty1(q) != 1)
		{
			Push2(q, Pop1(q));
		}
	}	
	int x = Pop2(q);
	if(x == q->max)
	{
		q->max = -2000000000;
		NEWMAX(q);
	}
	return x;
}


int main(void)
{
	struct circbuf q;
	int n;
	scanf("%d", &n);
	InitDoubleStack(&q, n);
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
					Enqueue(&q, x);
					
				}
				else
				{
					if(QueueEmpty(&q) == 1)
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
			case 'M':
			{
				printf("%d \n", q.max);
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
