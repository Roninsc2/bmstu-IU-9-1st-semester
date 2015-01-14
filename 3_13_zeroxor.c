#include <stdio.h>
#include <stdlib.h>

struct elem
{
        long int v;
	long int k;
	struct Elem *next;
};

unsigned long int result;


struct elem * ListSearch(struct elem * list, long int k);
struct elem * InsertBeforeHead(struct elem * list, long int k);
struct elem ** InitHashTable(long int m);

int main(void)
{
	long int n;
	long int temp = 0;
	result = 0;
	scanf("%ld", &n);
	struct elem * elemTemp;
	struct elem * y = NULL;
	struct elem ** table = InitHashTable(n);
	long int * arr = malloc(sizeof(long int)*n);
	long int i = 0;
	long int j = 0;
	table[0] = InsertBeforeHead(table[0], 0);
	for(i = 0; i < n;i++)
	{
		scanf("%ld", &arr[i]);
	}
	for(i = 0; i < n; i++)
	{
		temp = temp ^ arr[i];
		j = temp % n;
		y = ListSearch(table[j],temp);
		if(y == NULL)
		{
			table[j] = InsertBeforeHead(table[j], temp);
		}
		else
		{
			result += y->v;
			y->v++;
		}
	}
	for(i = 0; i < n; i++)
	{
		while(table[i] != NULL)
		{
			elemTemp = table[i];
			table[i] = elemTemp->next;
			result = result + elemTemp->v;
			free(elemTemp);
		}
	}
	printf("%lu \n", result);
	free(table);
	free(arr);
	return 0;
}

struct elem * ListSearch(struct elem * list, long int k)
{
	struct elem * temp = list;
	while(temp != NULL && temp->k != k)
	{
		temp = temp->next;
	}
	return temp;
	
}

struct elem * InsertBeforeHead(struct elem * list, long int k)
{
	struct elem * y = (struct elem *)malloc(sizeof(struct elem));
	y->next = list;
	y->k = k;
	y->v = 0;
	list = y;
	return list;
}

struct elem ** InitHashTable(long int m)
{
	struct elem ** table = (struct elem **)calloc(m,sizeof(struct elem*));
	return table;
}
