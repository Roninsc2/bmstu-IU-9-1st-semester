#include <stdio.h>
#include <stdlib.h>
 
 
struct Task 
{ 
        int low, high;
};
 
struct stack//стек с массивом task'ов
{
	struct Task * data;
	int cap;
	int top;
}s;
 
void qsstack(int * arr, int nel);//функция нерекурсивной сортировки
int partition(int low, int high, int * arr);//фунция возвращает границу разделения
 
int stackEmpty(void)//пустой ли стек?
{
	if(s.top == 0)
	{	
		return 0;
	}
	else
	{
		return 1;
	}
}
 
void push(int left, int right)//прибавление к стеку
{
	if(s.top == s.cap)
	{
		printf("The End");
		return;
	}
	s.data[s.top].low = left;
	s.data[s.top].high = right;
	s.top++;
}
 
struct Task pop(void)//удаление из стека
{
	if(stackEmpty() == 0)
	{
		printf("ERROR");
		return;
	}
	s.top--;
	return s.data[s.top];
}
 
int main(void)
{
	int nel;
	scanf("%d", &nel);
	s.top = 0;
	s.cap = nel;
	s.data = (struct Task *)malloc(sizeof(struct Task) * nel);//массив task'ов размером nel
	int * arr = (int *)malloc(nel*sizeof(int));//сортируемый массив
	int i;
	for(i = 0; i < nel; i++)
	{
		scanf("%d", &arr[i]);
	}
	qsstack(arr, nel);
	for(i = 0; i < nel; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);
	free(s.data);
	return 0;
}
 
void qsstack(int * arr, int nel)
{
        push(0, nel-1);//первое задания
	struct Task temp;
	int t = 0;	
	int i = 0;
	int j = 0;
	int base = 0;
	int left = 0, right = nel-1;
	while(stackEmpty() > 0)
	{
		temp = pop();//берем первое задание
		left = temp.low;//границы left и right
		right = temp.high;
		base = partition(left, right, arr);
		if(left < base)
		{
			push(left, base-1);//задаем последующие задания
		}
		if(base < right)
		{
			push(base+1, right);
		}
		
	}
}
 
 
 
int partition(int low, int high, int * arr)
{
	int i = low;
	int j = low;
	int t = 0;
	while(j < high)
	{
		if(arr[j] < arr[high])
		{
			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
			i++;
		}
		j++;
	}
	t = arr[i];
	arr[i] = arr[high];
	arr[high] = t;
	return i;
}
