#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delta1(char * str, int * delta1Arr);
void delta2(char * str, int * arr);
void suffix(char * str, int * arr);
void bmSubst(char * str, char * mainStr, int * deltaArr);

const int size = 26;

int main(int argc, char ** argv)
{	
	int * arr = malloc(sizeof(int) * size);
	bmSubst(argv[1], argv[2], arr);
	printf("\n");
	free(arr);
	return 0;
}

void suffix(char * str, int * arr)
{
	int k = strlen(str);
	int t = k - 1;
	arr[k-1] = t;
	int i = k - 2;
	while(i >= 0)
	{
		while(t < (k-1) && str[t] != str[i])
		{
			t = arr[t + 1];
		}
		if(str[t] == str[i])
		{
			t--;
		}
		arr[i] = t;
		i--;
	}
}

void delta2(char * str, int * arr)
{
	int k = strlen(str);
	int * suffixArr = calloc(k, sizeof(int));
	suffix(str, suffixArr);
	int i = 0;
	int t = suffixArr[0];
	while(i < k)
	{
		while(t < i)
		{
			t = suffixArr[t+1];
		}
		arr[i] = t - i + k;
		i++;
	}
	i = 0;
	while(i < (k - 1))
	{
		t = i;
		while(t < (k-1))
		{
			t = suffixArr[t+1];
			if(str[i] != str[t])
			{
				arr[t] = k - i - 1;
			}
		}
		i++;
	}
	free(suffixArr);
}


void delta1(char * str, int * deltaArr)
{
	int i = 0;
	int j = 0;
	int k =  strlen(str);
	while(i < size)
	{
		deltaArr[i] = k;
		i++;
	}
	while(j < k)
	{
		deltaArr[str[j] - 97] = k - j - 1;
		j++;
	}
}

void bmSubst(char * str, char * mainStr, int * delta1Arr)
{
	int x = strlen(mainStr);
	int y = strlen(str);
	int * delta2Arr = calloc(y, sizeof(int));
	delta1(str, delta1Arr);
	delta2(str, delta2Arr);
	int k = strlen(str) - 1;
	int i = 0;
	while(k < x)
	{
		i = y - 1;
		while(mainStr[k] == str[i])
		{
			if(i == 0)
			{
				printf("%d ", k);
				break;
			}
			i--;
			k--;

		}
		if(delta1Arr[mainStr[k] - 97] > (delta2Arr[i]))
		{
			k += delta1Arr[mainStr[k] - 97];
		}
		else
		{
			k += delta2Arr[i];
		}
	}
	free(delta2Arr);
}
