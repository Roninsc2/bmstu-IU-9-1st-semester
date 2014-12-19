#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefix(char * str, int * arr);

int main(int argc, char ** argv)
{
	int len = strlen(argv[1]);
	int prefLen = 0;
	int count = 0;
	int countPrefLen = 0;
	int * arr = calloc(len, sizeof(int));
	prefix(argv[1], arr);
	int i = 0;	
	int j = 0;
	while(j < len)
	{
		if(arr[j] != 0)
		{
			i = j;
			prefLen = j + 1;
			countPrefLen = prefLen - arr[j];
			count = 1;
			while(countPrefLen == (arr[i] - arr[arr[i] - 1]) || countPrefLen == arr[i])
			{
				count++;
				i = arr[i] - 1;
				if(i + 1 == countPrefLen)
				{
					printf("%d %d \n", prefLen, count);
					break;
				}
			}			
		}
		j++;
	}
	free(arr);
	return 0;
}


void prefix(char * str, int * arr)
{
	int len = strlen(str);
	int t = 0;
	arr[0] = t;
	int i = 1;
	while(i < len)
	{
		while(t > 0 && str[i] != str[t])
		{
			t = arr[t-1];
		}
		if(str[i] == str[t])
		{
			t++;
		}
		arr[i] = t;
		i++;
	}
	
}
