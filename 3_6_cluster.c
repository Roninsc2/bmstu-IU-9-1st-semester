//1)Вы не проверили 2 задачи из 2-ого модуля. Прошу Вас засчитать мне их.
//2)я делал через массив, размер которого равен кол-ву узлов, в котором храниться сумма на всех узлах
//и вытаскиавал минимальное время, к которому прибавлял время выполения следующей задачи по списку
//затем я просто брал максимальное время

#include <stdio.h>
#include <stdlib.h>

struct sort
{
        int * sumTime;//heap не нужен, так как sumTime является и ключем, и значением
        int cap;
	int count;
};

void InitPriorityQueue(struct sort * q,int k);
int QueueEmpty(struct sort * q);
void Insert(struct sort * q, int enter);
int ExtractMin(struct sort * q);
void heapify(struct sort * q, int i, int nel);
void HelpInsert(struct sort * q, int time1, int time2, int N);
int Max(struct sort * q);


int main(void)
{
	int N;
	scanf("%d", &N);
	struct sort q;
	InitPriorityQueue(&q, N);
	int M;
	scanf("%d", &M);
	int time1, time2;
	int i, j = 0;
	int enter;
	for(i = 0 ; i < N; i++)//сначала вводим первые задачи, чтоб затем от них отталкиваться
	{
		if(i == M)//если последовательность меньше, чем кол-во узлов
		{
			printf("%d \n", Max(&q));
			return 0;
		}
		scanf("%d %d", &time1, &time2);
		enter = time1 + time2;
		Insert(&q, enter);
		 
	}
	M -= N;
	for(i = 0; i < M; i++)
	{
		scanf("%d %d", &time1, &time2);
		HelpInsert(&q,time1, time2, N);
	}
	printf("%d \n", Max(&q));
	free(q.sumTime);
	return 0;

}

int Max(struct sort * q)//нахождения максимального времени
{
	int max = -1;
	int i;
	for(i = 0; i < q->count; i++)
	{
		if(max < q->sumTime[i])
		{
			max = q->sumTime[i];
		}
	}
	return max;
}

int QueueEmpty(struct sort * q)//проверка на пустоту
{
	if(q->count)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void InitPriorityQueue(struct sort * q,int k)//функция инициализации массива
{
	q->sumTime = (int *)malloc(sizeof(int) * k);//берем массив, размер которого равен кол-ву узлов
	q->cap = k;
	q->count = 0;
}

void Insert(struct sort * q, int enter)//функция ввода
{
	int i = q->count;
	int temp;
	if(i == q->cap)
	{
		return;
	}
	q->count++;
	q->sumTime[i] = enter;
	while(i > 0 && q->sumTime[(i - 1)/2] >= q->sumTime[i])
	{
		temp = q->sumTime[(i - 1)/2];
		q->sumTime[(i - 1)/2] = q->sumTime[i];
		q->sumTime[i] = temp;
		i = (i - 1)/2;
	}
		
}

void HelpInsert(struct sort * q, int time1, int time2, int N)
{
	int enter = ExtractMin(q);//берем самое мальнькое время
	if(enter < time1)//если задача выполнилась за время, меньшее, чем надо для начала следующей
        //то вычитаем 
	{
		enter += time1 - enter + time2;
	}
	else//в противном случае прибавляем время следующей задачи.
	{
		enter += time2;
	}
	Insert(q, enter);
}

int ExtractMin(struct sort * q)
{	
	if(QueueEmpty(q))
	{
		return;
	}
	int min = q->sumTime[0];
	q->count--;
	int i = 0;
	if(q->count > 0)
	{
		q->sumTime[0] = q->sumTime[q->count];
		heapify(q, 0, q->count);
	}
	return min;
}

void heapify(struct sort * q, int i, int nel)
{
    	int l = 0;
	int j = 1; 
	int r = 0;
	int temp;
	while(1)
	{
		l = 2*i + 1;
		r = l + 1;
		j = i;
		if (l < nel && q->sumTime[i] > q->sumTime[l])
		{
			i = l;
		}
        	if (r < nel && q->sumTime[i] > q->sumTime[r]) 
		{
			i = r;
		}
		if (i==j) 
		{
			break;
		}
		temp = q->sumTime[i];
		q->sumTime[i]= q->sumTime[j];
		q->sumTime[j] = temp;
		
		
	}
}
