#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	const int N = 64;
	long long x = 0;
	long long a = 0;
	long long b = 0;
	long long m = 0;
	int massiveB[N];
	int i = 0;
	scanf("%lld %lld %lld", &a, &b, &m);
	if(a <= 0 || b <= 0 || m <= 0)
	{
		return 1;
	}
	for(i = (N-1); i >= 0; i--)
	{
		massiveB[i] = b%2;
		b = b/2;
	}
	x = (massiveB[0]*a) % m;
	for(i = 1; i < N; i++)
	{
		x = (((x*(2 % m)) % m) + ((a * massiveB[i]) % m)) % m;
	}
	printf("%lld \n", x);

	return 0;
}
