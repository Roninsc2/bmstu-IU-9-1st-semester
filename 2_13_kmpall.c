#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prefix(char * str, int * arr);
void kmpSubst(char * prefStr, char * mainStr, int * arr);

int main(int argc, char ** argv)
{
	int * arr = malloc(sizeof(int)*strlen(argv[1]));
	kmpSubst(argv[1], argv[2], arr);
	printf("\n");
	free(arr);
	return 0;
}

int prefix(char * str, int * arr)
{
	int t = 0;
	arr[0] = t;
	int i = 1;
	int k = strlen(str);
	while(i < k)
	{
		while(t > 0 && str[t] != str[i])
		{
			t = arr[t-1];
		}
		if(str[t] == str[i])
		{
			t++;
		}
		arr[i] = t;
		i++;
	}
}


void kmpSubst(char * prefStr, char * mainStr, int * arr)
{
	prefix(prefStr, arr);
	int prefCount = 0;
	int mainCount = 0;
	int k = strlen(mainStr);
	while(mainCount < k)
	{
		while(prefCount > 0 && prefStr[prefCount] != mainStr[mainCount])
		{
			prefCount = arr[prefCount-1];
		}
		if(prefStr[prefCount] == mainStr[mainCount])
		{
			prefCount++;
		}
		if(prefCount == strlen(prefStr))
		{
			printf("%d ", (mainCount - strlen(prefStr) + 1));
		}
		mainCount++;
		
	}
}
