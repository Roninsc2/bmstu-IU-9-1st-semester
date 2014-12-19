#include <stdio.h>
#include <stdlib.h>

int main(void)
{
int n = 0;
int k = 0;
int f = 0;
scanf("%d", &n);
if(n > 1000000 || n < 0)
{
	return 1;
}
int * massive = malloc (sizeof(int) * n);
int i = 0;
int j = 0;
long int sum = 0;
long int maxSum = 0;
for(i = 0; i < n; i++)
{
	scanf("%d", &massive[i]);	
}
scanf("%d", &k);
if(k > n || k < 0)
{
	return 1;
}
for(i = 0; i < k; i++)
{
	maxSum += massive[i];
}
f = k;
sum = maxSum;
for(i = 0; i < (n-k); i++)
{
	sum = sum - massive[i] + massive[f];
	if(sum >=  maxSum)
	{
	maxSum = sum;
	}
	f++;
}
printf("%ld \n", maxSum);
free(massive);
return 0;
}
