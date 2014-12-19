#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deltaPlus(char * str, int * arr);
int simpleBMsubst(char * str, char * mainStr);

const int size = 26;

int main(int argc, char ** argv)
{
	simpleBMsubst(argv[1], argv[2]);
	printf("\n");
	return 0;
}

void deltaPlus(char * str, int * arr)
{
	int len = strlen(str);
	int i = 0;
	int j = 0;
	for(i = 0; i < len; i++)
	{
		for(j = 0; j < size; j++)
		{
			arr[i*size + j] = len;
		}
	}
	for(i = 0; i < len; i++)
	{
		for(j = 0; j < i; j++)
		{
			arr[i*size + str[j] - 97] = len - j - 1;
		}
	}
}

int simpleBMsubst(char * str, char * mainStr)
{
	int len = strlen(str);
	int * deltaArr = calloc(len*size,sizeof(int));
	int i = 0;
	deltaPlus(str, deltaArr);
	int k = len - 1;
	int j = 0;
	int mainLen = strlen(mainStr);
	while(k < mainLen)
	{
		i = len - 1;
		while(mainStr[k] == str[i])
		{
			if(i == 0)
			{
				printf("%d ", k);
				free(deltaArr);
				return 1;
			}
			i--;
			k--;
		}
		if(deltaArr[i*size + mainStr[k] - 97] >= (len - i))
		{
			k += deltaArr[i*size + mainStr[k] - 97];
		}
		else
		{
			k += len - 1;
		}
	}
	printf("%d ", mainLen);
	free(deltaArr);
	return 0;
}
