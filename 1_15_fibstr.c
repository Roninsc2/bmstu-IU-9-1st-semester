#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fibstr(int n);

int main(void)
{
	int k = 0;
	scanf("%d", &k);
	char * p = 0;
	p = fibstr(k);
	puts(p);
	free(p);
	return 0;
}

char *fibstr(int n) 
{ 
	int x = 1;
	int y = 1;
	int strN = 0;
	int i = 0;
	for(i = 3; i <= n; i++)
	{
		strN = x + y;
		x = y;
		y = strN;
		
	}
	if(n < 3)
	{
		strN = 1;
	} 
	strN += 1;
	char * mas0 = malloc(strN * sizeof(char));
	char * mas1 = malloc(strN * sizeof(char));
	mas0[0] = 'a';
	mas1[0] = 'b';
	for(i = 3; i <= n; i++)
	{
		if(i % 2 != 0)
		{
			strcat(mas0, mas1);
		}
		else
		{
			strcat(mas1, mas0);
		}
	}
	if(n % 2 != 0)
	{
		free(mas1);
		return mas0;
	}
	else
	{
		free(mas0);
		return mas1;
	}
}
