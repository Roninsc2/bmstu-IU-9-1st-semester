#include <stdlib.h>
#include <stdio.h>

struct elem
{
	int v;
	int k;
	struct Elem *next;
};

struct elem ** InitHashTable(int m);
struct elem * ListSearch(struct elem * list, int k);
int Lookup(struct elem ** table, int i, int m);
struct elem ** Insert(struct elem **table, int k, int v, int m);
struct elem * InsertBeforeHead(struct elem * list, int k, int v);

void freeList(struct elem * list)
{
	struct elem * temp;
	while(list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}

void freeTable(struct elem ** table, int m)
{
	int i;
	for(i = 0; i < m; i++)
	{
		freeList(table[i]);
	}
	free(table);
}


int main(void)
{
	int n;
	int m;
	scanf("%d %d", &n, &m);
	struct elem ** table = InitHashTable(m);
	int i = 0;
	int k;
	int v;
	char word[7];
	for(i = 0; i < n; i++)
	{
		scanf("%s", word);
		if(word[0] == 'A' && word[1] == 'T')
		{
			scanf("%d", &k);
			v = Lookup(table, k, m);
			printf("%d\n", v);
		}
		else
		{
			scanf("%d %d", &k, &v);
			table = Insert(table, k, v, m);
		}
	}
	freeTable(table, m);
	return 0;
}

struct elem * ListSearch(struct elem * list, int k)
{
	struct elem * temp = list;
	while(temp != NULL && temp->k != k)
	{
		temp = temp->next;
	}
	return temp;
	
}

struct elem * InsertBeforeHead(struct elem * list, int k, int v)
{
	struct elem * y = (struct elem *)malloc(sizeof(struct elem));
	y->next = list;
	y->k = k;
	y->v = v;
	list = y;
	return list;
}

struct elem ** Insert(struct elem ** table, int k, int v, int m)
{
	int i = k % m;
	table[i] = InsertBeforeHead(table[i], k, v);
	return table;
}

int Lookup(struct elem ** table, int k, int m)
{
	int i = k % m;
	struct elem * result = ListSearch(table[i], k);
	if(result == NULL)
	{
		return 0;
	}
	else
	{
		return result->v;
	}
}

struct elem ** InitHashTable(int m)
{
	struct elem ** table = (struct elem **)calloc(m,sizeof(struct elem*));
	int i;
	return table;
}
