#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int s = strlen(argv[1]);
	int t = strlen(argv[2]);
	int i = 0;
	int j = 0;
	int count = 0;
	for(i = 0; i < t; i++)
	{
		if(j == s)
		{
			j = 0;
		}
		if(((argv[2][i]) != (argv[1][j])) && (i == (t-1) || i == 0))
		{
			printf("no \n");
			return 0;
		}
		if((argv[2][i]) != (argv[1][j]))
		{
			j = 0;
			i--;
			if(count == 1)
			{
				printf("no \n");
				return 0;
			}
			count = 1;
		}
		else
		{
			count = 0;
		}
		j++;
	}
	printf("yes \n");
	return 0;
}
