#include <stdio.h>

int less(unsigned long long i, unsigned long long j)
{
	if (i == j) return 0;

	if (i < j) {
		if (j <= 11241155978086311589ULL) return 1;
		if (i >= 11241155978086311589ULL) return 0;
		return (11241155978086311589ULL-i) < (j-11241155978086311589ULL);
	}

	if (i <= 11241155978086311589ULL) return 0;
	if (j >= 11241155978086311589ULL) return 1;
	return (11241155978086311589ULL-j) < (i-11241155978086311589ULL);
}

unsigned long long peak(unsigned long long, int (*)(unsigned long long, unsigned long long));

int main(int argc, char **argv)
{
	peak(13356955260197607378ULL, less);
	unsigned long long i = peak(13356955260197607378ULL, less);
	if (i == 11241155978086311589ULL) {
		printf("CORRECT\n");
	} else {
		printf("WRONG\n");
	}
	return 0;
}


unsigned long long peak(unsigned long long nel, int (*less)(unsigned long long i, unsigned long long j)) 
{ 
	if(nel > 1)
	{
		if(less(0, 1) == 0)
		{
			return 0;
		}
		else
		{
			if(less(nel-2, nel-1) == 1)
			{
				return (nel-1);	
			}
		}
	}
	else
	{
		return 0;
	}
	unsigned long long low = 0;
	unsigned long  long mid = 0;
	unsigned long long high = nel - 1;  
	int i = 0;      
	while(low <= high)
	{
		mid = (high - low)/2 + low;	
		printf("%llu %llu %llu \n", mid - 1, mid, mid + 1);
		if(less(mid-1,mid) == 1 && less(mid, mid+1) == 0)
		{
			return mid;
		}
		else
		{
			if(less(mid-1, mid) == 1)
			{
				low = mid + 1;
				printf("1 \n");
			}	
			else
			{
				high = mid - 1;
			}
		}
	}
}

//printf("%d \n", i);
