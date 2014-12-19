#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
 
unsigned char array[] = { 153 , 1 , 15 , 191 , 232 , 251 , 27 , 174 , 26 , 3 , 68 , 48};

int compare(void *a, void *b)
{
	return (int)(*(unsigned char*)a) - (int)(*(unsigned char*)b);
} 
 
int maxarray(void *base, unsigned long nel, unsigned long width, 
        int (*compare)(void *a, void *b)) ;
 
int main(int argc, char **argv) 
{ 
        printf("%d\n", maxarray(array, 12, sizeof(unsigned char), compare));
        return 0; 
}


int maxarray(void *base, unsigned long nel, unsigned long width, int (*compare)(void *a, void *b)) 
{ 
	void *p = malloc(width);
	int i = 0;
	int k = 0;
	memcpy(p, base, width);
	for(i = 1; i < nel; i++)
	{
		if(compare(p, (base+i*width)) < 0)
		{
		memcpy(p, (base + i*width), width);
		k = i;
		}
	}
	free(p);
	return k;
}
