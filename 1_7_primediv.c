#include <stdio.h>
#include <strlib.h>
#include <math.h>

int main()
{
	int x = 0;
	int answer = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	scanf("%d", &x);
	if(x<0) 
	{
		x = -x; 
	}
	k = sqrt(x) + 1;
	int mas[k];
	for (i = 0; i < k; i++)
	{
		mas[i] = i;
	}
	mas[1]=0;
	for(i = 2; i < k; i++)
	{
		if(mas[i] != 0)
		{
			for(j=i*i; j < k; j += i)
			{
				mas[j]=0;
			}
		}
	}
	answer = x;
	for(i = 2;i < k; i++)
	{
		if(mas[i]!= 0 && x % mas[i] == 0)
		{
			while(x % mas[i]==0 && x / mas[i] > 1)
			{
				x = x / mas[i]; 
				answer = mas[i]; 
			}
		}
		else 
		{
			answer = x;
		}
	}
	printf("%d\n", answer);
	return 0;
}



/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int x);


int main(void)
{
int n = 0;
scanf("%d", &n);
if(abs(n) == 1 || abs(n) == 0)
{
return 1;
}
if(isPrime(abs(n)) == 1)
{
	printf("%d ", n);
	return 0;
}
int f = abs(n)/2;
int i = 0;
if(f % 2 == 0 && f != 2)
{
	f = f + 1;
}
for(i = f; i >= 2; i = i - 2)
{
	if(n % i == 0)
	{
		if(isPrime(i) == 1)
		{
			printf("%d ", i);
			{
			return 0;
			}
		}
	}
}
return 0;
}


int isPrime(int x)
{
int j = 0;
int i = 0;
if(x % 2 == 0 && x != 2)
{
return 0;
}
for(i = 3; i*i <= x; i+= 2)
{
	for(j = i*i; j <= x; j+=i)
	{
	if(x % j == 0)
	{
	return 0;
	}
	}
}

return 1;
}


int isPrime(int x)
{
int k = (int) sqrt((double)x);
int i = 0;
if(x % 2 == 0 && k >=2)
{
	return 0;
}
for(i = 3; i <= k; i+= 2)
{
	if(x % i == 0)
	{
		return 0;
	}
}
return 1;
}*/
