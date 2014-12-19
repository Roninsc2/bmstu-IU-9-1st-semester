#include <stdio.h>
#include <stdlib.h>

struct stack
{
	int * data;
	int top;
	int cap;
};

int stackEmpty(struct stack * s)//пустой ли стек?
{
	if(s->top == 0)
	{	
		return 0;
	}
	else
	{
		return 1;
	}
}
 
void push(int x, struct stack * s)//прибавление к стеку
{
	if(s->top == s->cap)
	{
		printf("The End");
		return;
	}
	s->data[s->top] = x;
	s->top++;
}
 
int pop(struct stack *s)//удаление из стека
{
	if(stackEmpty(s) == 0)
	{
		printf("Stack Is Empty");
		return;
	}
	s->top--;
	return s->data[s->top];
}

void constS(int x, struct stack * s);
void add(struct stack * s);
void sub(struct stack * s);
void mul(struct stack * s);
void divS(struct stack * s);
void max(struct stack * s);
void min(struct stack * s);
void neg(struct stack * s);
void dup(struct stack * s);
void swap(struct stack * s);

int main(void)
{
	struct stack s;
	int n;
	scanf("%d", &n);
	s.top = 0;
	s.cap = n;
	s.data = (int *)malloc(n * sizeof(int));
	char str[5];
	int i = 0;
	int x = 0;
	for(i = 0; i < n; i++)
	{
		scanf("%s", str);
		switch (str[0])
		{
			case  'C':
			{
				scanf("%d", &x);
				constS(x, &s);
				break;
			}
			case 'A':
			{
				add(&s);
				break;
			}
			case 'S':
			{	
				if(str[1] == 'U')
				{
					sub(&s);
				}
				else
				{
					swap(&s);
				}
				break;
			}
			case 'M':
			{
				if(str[1] == 'U')
				{
					mul(&s);
				}
				if(str[1] == 'A')
				{
					max(&s);
				}
				if(str[1] == 'I')
				{
					min(&s);
				}
				break;
			}
			case 'N':
			{
				neg(&s);
				break;
			}
			case 'D':
			{
				if(str[1] == 'I')
				{
					divS(&s);
				}
				else
				{
					dup(&s);
				}
				break;
			}
			default:
			{
				printf("Error");
			}
			
		}
	}
	printf("%d \n", pop(&s));
	free(s.data);
	return 0;
}

void constS(int x, struct stack * s)
{
	push(x, s);
}

void add(struct stack * s)
{
	int a = pop(s);
	int b = pop(s);
	push(a+b, s);
}

void sub(struct stack * s)
{
	int a = pop(s);
	int b = pop(s);
	push(a-b, s);
}

void mul(struct stack * s)
{
	int a = pop(s);
	int b = pop(s);
	push(a*b, s);
}

void divS(struct stack * s)
{
	int a = pop(s);
	int b = pop(s);
	push(a/b, s);
}

void max(struct stack * s)
{
	int a = pop(s);
	int b = pop(s);
	if(a > b) 
	{
		push(a, s);
	}
	else
	{
		push(b, s);
	}
}

void min(struct stack * s)
{
	int a = pop(s);
	int b = pop(s);
	if(a < b) 
	{
		push(a, s);
	}
	else
	{
		push(b, s);
	}
}

void neg(struct stack * s)
{
	int a = pop(s);
	a *= -1;
	push(a, s); 
}

void dup(struct stack * s)
{
	int a = pop(s);
	push(a,s);
	push(a,s);
}

void swap(struct stack * s)
{
	int a = pop(s);
	int b = pop(s);
	push(a,s);
	push(b,s);
}
