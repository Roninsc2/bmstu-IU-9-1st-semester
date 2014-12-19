#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

int array[] = { 
        1, 
        2, 
        3, 
        4, 
        5,
	6
}; 
 
void revarray(void *base, unsigned long nel, unsigned long width);
 
int main(int argc, char **argv) 
{ 
        revarray(array, 6, sizeof(int)); 
 
        int i; 
        for (i = 0; i < 6; i++) { 
                printf("%d\n", array[i]); 
        }
 
        return 0; 
}

void revarray(void *base, unsigned long nel, unsigned long width)
{
	void *p = malloc(width);
	int i = 0;
	for(i = 0; i < nel/2; i++)
	{ 
		memcpy(p, (base + i*width), width);
		memcpy((base + i*width), (base + (nel - 1 - i)*width), width);
		memcpy((base + (nel - 1 - i)*width), p, width);
		
	}
	free(p);
}
