#include <stdio.h>
#include <stdlib.h>

unsigned int expansionInBits(int a);
int bit(unsigned int *x);

int main(void)
{
	int n = 0;
	int k = 0;
	int i = 0;
	unsigned int nBit = 0;
	unsigned int kBit = 0;
	unsigned int sumK_N = 0;
	int nMas = 0;
	int kMas = 0;
	//first massive
	scanf("%d", &n);
	if(n == 0)
	{
		return 0;
	}
	else
	{
		if(n > 32)
		{
			return 1;
		}
	}
	for(i = 0; i < n; i++)
	{
		scanf("%d", &nMas);
		if(nMas < 0 || nMas > 31)
		{
			return 1;
		}
		nBit = nBit + expansionInBits(nMas);
	}
	//second massive
	scanf("%d", &k);
	if(k == 0)
	{
		return 0;
	}
	else
	{
		if(k > 32)
		{
			return 1;
		}
	}
	for(i = 0; i < k; i++)
	{
		scanf("%d", &kMas);
		if(kMas < 0 || kMas > 31)
		{
			return 1;
		}
		kBit = kBit + expansionInBits(kMas);
	}
	sumK_N = kBit & nBit;
	if(sumK_N == 0)
	{
		return 0;
	}
	while(sumK_N != 0)
	{
		printf("%u \n", bit(&sumK_N));
	}
	return 0;
}

unsigned int expansionInBits(int a)
{
	int i = 0;
	unsigned int k = 0;
	k = 1 << a;
	return k;
}

int bit(unsigned int *x)
{
	unsigned int t = 1;
	int i = 0;
	while(*x > t)
	{
		t = t << 1;
		i++;
	if((t & *x) > 0)
	{
		break;
	}
	}
	*x = *x - t;
	return i;
}
