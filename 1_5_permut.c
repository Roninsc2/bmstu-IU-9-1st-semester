#include <stdio.h>
#include <stdlib.h>

const int N = 8;

int main(void)
{
int str1[N];
int str2[N];
int i = 0;
int j = 0;
int k = 0;
int sumStr1 = 0;
for(i = 0; i < N; i++)
{
	scanf("%d", &str1[i]);
	sumStr1 += str1[i];
}
sumStr1 += 2;
for(i = 0; i < N; i++)
{
	scanf("%d", &str2[i]);
}
for(i = 0; i < N; i++)
{
	k = 0;
	for(j=0; j < N; j++)
	{
		if(str1[i] == str2[j])
		{
		str2[j] = sumStr1;
		k = 1;
		break;
		}
	}
	if(k == 0)
	{
		printf("no \n");
		return 1;
	}
}
printf("yes \n");
return 0;
}
