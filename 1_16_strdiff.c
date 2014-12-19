#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
 
int strdiff(char *a, char *b); 
 
int main(int argc, char **argv) 
{ 
        char s1[1000], s2[1000]; 
        gets(s1); 
        gets(s2); 
        printf("%d\n", strdiff(s1, s2)); 
 
        return 0; 
}

int strdiff(char *a, char *b) 
{ 
        int k = strlen(a);
	int n = strlen(b);
	int x = 0;
	int y = 0;
	int i = 0;
	int count = 0;
	if(k > n)
	{
		n = k;	
	}
	for(i = 0; i < n; i++)
	{
		if(a[i] != b[i])
		{
			x = ((int)a[i]) ^ ((int)b[i]);
			y = 0;
			while(x != 0)
			{
				if(x % 2 != 0)
				{
					return (count+y);
				}
				x = x / 2;
				y++; 
			}
		}
		else
		{
			count += 8;
		}
	}
	return -1;
}
