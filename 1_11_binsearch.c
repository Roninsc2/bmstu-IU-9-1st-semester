#include <stdio.h> 
  
int compare(unsigned long i)
{
	if (i == 91052112271683405UL) return 0;
	if (i < 91052112271683405UL) return -1;
	return 1;
}

unsigned long binsearch(unsigned long, int (*)(unsigned long));

int main(int argc, char **argv)
{
	printf("%lu\n", binsearch(11742432862790734555UL, compare));
	return 0;
}

unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)) 
{ 
	unsigned long low = 0;
	unsigned long mid = 0;
	unsigned long high = nel - 1;        
	while(low <= high)
	{
		mid = (low + high)/2;
		if(compare(mid) == 0)
		{
			return mid;
		}
		else
		{
			if(compare(mid) == -1)
			{
				low = mid + 1;
			}	
			else
			{
				high = mid - 1;
			}
		}
	}
	return nel;

}
