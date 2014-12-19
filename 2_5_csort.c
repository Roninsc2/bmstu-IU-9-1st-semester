#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void csort(char *src, char *dest);

int main(void)
{
	char * str = malloc(sizeof(char) * 200);
	gets(str);
	int count = 0;
	const int N = strlen(str); 
	int i = 0;
	for(i = 0; i < N; i++)
	{
		if(str[i] != ' ')
		{	
			while(i < N)
			{
				count++;
				i++;
				if(str[i] == ' ')
				{
					count++;
					break;
				}
			}		
		}
	}
	char * resultStr = calloc((count+2),sizeof(char));
	csort(str, resultStr);
	printf("%s \n", resultStr); 
	free(str);
	free(resultStr);
	return 0;
}

void csort(char *src, char *dest) 
{ 	
	int nel = 0;
	const int N = strlen(src); 
	int count = 0;
	int i = 0;
	int j = 0;
	for(i = 0; i < N; i++)
	{
		if(src[i] != ' ')
		{	
			nel++;
			while(i < N)
			{
				i++;
				if(src[i] == ' ')
				{
					break;
				}
			}		
		}
	}
	int * keyArr = calloc(2*nel,sizeof(int));
	int * countArr = calloc(nel,sizeof(int));
	j = 0;
	for(i = 0; (i < N && j < nel); i++)
	{
		if(src[i] != ' ')
		{
			count = 0;
			keyArr[j] = i;
			while(i < N)
			{
				count++;
				i++;
				if(src[i] == ' ')
				{
					break;
				}
			}
			keyArr[j+nel] = count;
			j++;
		}
	}
	j = 0;
	while(j < (nel-1))
	{
		i = j +1;
		while(i < nel)
		{
			if(keyArr[i+nel] < keyArr[j+nel])
			{
				countArr[j]++;
			}
			else
			{
				countArr[i]++;
			}
			i++;
		}
		j++;
	}
	j = 0;
	count = 0;
	strncat(src, " ", 1);
	while(j < nel)
	{
		for(i = 0; i < nel; i++)
		{
			if(countArr[i] == j)
			{
				strncat(dest, (src+keyArr[i]), (keyArr[i + nel] + 1));
				break;
			}
		}
		j++;
	}
	free(keyArr);
	free(countArr);
}
