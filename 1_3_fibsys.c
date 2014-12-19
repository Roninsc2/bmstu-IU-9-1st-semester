#include <stdio.h>
#include <stdlib.h>

long long fibonachi(long long *x);

int main(void)
{
	long long x = 0;
	scanf("%lld", &x);
	if(x < 0)
	{
		return 1;
	}
	if(x == 0)
	{
		printf("%lld \n", x);
		return 0;
	}
	long long n = fibonachi(&x);
	long long k = 0;
	long long i = 0;
	int * fibsys = malloc (sizeof(int) * n);
	fibsys[0] = 1;
	for(i = 1; i < n; i++)
	{
		fibsys[i] = 0;
	}
	while(x > 0)
	{
		k = fibonachi(&x);
		fibsys[n-k] = 1;
	}
	for(i = 0; i < n; i++)
	{
		printf("%d", fibsys[i]);
	}
	printf("\n");
	free(fibsys);
	return 0;
}

long long fibonachi(long long  *x)
{
	long long i = 0;
	long long fibMax = 0;
	unsigned long long b = 0;
	unsigned long long a = 1;
	while(*x > fibMax)
	{
		if((a+b) > *x)
		{
			break;
		}
		fibMax = a + b;
		b = a;
		a = fibMax;
		i++;
	}
	*x = *x - fibMax;
	return i;
}
