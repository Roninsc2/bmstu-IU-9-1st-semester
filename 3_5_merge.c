#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct forHeap
{
	int indexK;
	int indexNel;
	int v;
};

struct sort
{
	struct forHeap * heap;
	int cap;
	int count;
};

void InitPriorityQueue(struct sort * q,int k);
int QueueEmpty(struct sort * q);
void Insert(struct sort * q, struct forHeap a);
struct forHeap ExtractMin(struct sort * q);
void heapify(struct sort * q, int i, int nel);
void HelpInsert(struct sort * q, int ** pArr, int k, int * nelArr);




int main(void)
{
	struct sort q;
	int k;
	int i, j;
	scanf("%d", &k);
	int * nelArr = malloc(sizeof(int) * k);
	for(i = 0; i < k;i++)
	{
		scanf("%d", &nelArr[i]);
	}
	int ** pArr = malloc(sizeof(int*) * k);
	int helpK = k;
	for(i = 0; i < k; i++)
	{
		if(nelArr[i] != 0)
		{
			pArr[i] = (int *)malloc(sizeof(int) * nelArr[i]);
			for(j = 0; j < nelArr[i]; j++)
			{
				scanf("%d", &pArr[i][j]);
			}
		}
	}
	InitPriorityQueue(&q, k);
	struct forHeap a;
	for(i = 0; i < k; i++)
	{
		if(nelArr[i] != 0)
		{
			a.indexK = i;
			a.indexNel = 0;
			a.v = pArr[i][0];
			Insert(&q, a);
		}
	}
	HelpInsert(&q, pArr, k, nelArr);
	for(i = 0; i < k; i++)
	{	
		if(nelArr[i] != 0)
		{
			free(pArr[i]);
		}
	}
	free(nelArr);
	free(pArr);
	free(q.heap);
	return 0;
}

void HelpInsert(struct sort * q, int ** pArr, int k, int * nelArr)
{
	if(QueueEmpty(q) == 1)
	{
		return;
	}
	struct forHeap temp;
	temp = ExtractMin(q);
	printf("%d ", temp.v);
	if(temp.indexNel == (nelArr[temp.indexK] - 1))
	{
		HelpInsert(q, pArr, k, nelArr);
	}
	else
	{
		temp.indexNel++;
		temp.v = pArr[temp.indexK][temp.indexNel];
		Insert(q, temp);
	}
	HelpInsert(q, pArr, k, nelArr);
}

void InitPriorityQueue(struct sort * q,int k)
{
	q->heap = (struct forHeap *)malloc(sizeof(struct forHeap) * k);
	q->cap = k;
	q->count = 0;
}


int QueueEmpty(struct sort * q)
{
	if(q->count == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Insert(struct sort * q, struct forHeap a)
{
	int i = q->count;
	struct forHeap temp;
	if(i == q->cap)
	{
		return;
	}
	q->count++;
	q->heap[i] = a;
	while(i > 0 && q->heap[(i - 1)/2].v >= q->heap[i].v)
	{
		temp = q->heap[(i - 1)/2];
		q->heap[(i - 1)/2] = q->heap[i];
		q->heap[i] = temp;
		i = (i - 1)/2;
	}
		
}

struct forHeap ExtractMin(struct sort * q)
{	
	if(QueueEmpty(q) == 1)
	{
		return;
	}
	struct forHeap ptr = q->heap[0];
	q->count--;
	int i = 0;
	if(q->count > 0)
	{
		q->heap[0] = q->heap[q->count];
		heapify(q, 0, q->count);
	}
	return ptr;
}

void heapify(struct sort * q, int i, int nel)
{
    	int l = 0;
	int j = 1; 
	int r = 0;
	struct forHeap temp;
	while(1)
	{
		l = 2*i + 1;
		r = l + 1;
		j = i;
		if (l < nel && q->heap[i].v > q->heap[l].v)
		{
			i = l;
		}
        	if (r < nel && q->heap[i].v > q->heap[r].v) 
		{
			i = r;
		}
		if (i==j) 
		{
			break;
		}
		temp = q->heap[i];
		q->heap[i]= q->heap[j];
		q->heap[j] = temp;
		
		
	}
}
