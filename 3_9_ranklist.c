#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct skipList
{
        char word[10];
	int k;
	int * span;
	struct skipList ** next;
};

struct skipList *InitSkipList(int m)
{
	struct skipList * list = (struct skipList * )malloc(sizeof(struct skipList));
	list->next = (struct skipList **)malloc(sizeof(struct skipList *)*m);
	list->span = (int *)malloc(sizeof(int)*m);
	int i = 0;
	while(i < m)
	{
		list->next[i] = NULL;
		i++;	
	}
	return list;
}

int MapEmpty(struct skipList *list)
{
	if(list->next[0] == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

struct skipList * Succ(struct skipList * x)
{
	return x->next[0];
}


void Skip(struct skipList *list, int m, int k, struct skipList ** p,int * listNumber)
{
	struct skipList * x = list;
	int i = m -1;	
	while(i >= 0)
	{
		listNumber[i] = i;
        	if(listNumber[i] == m-1) 
		{	
			listNumber[i] = 0;
		}
		else
		{
			listNumber[i] = listNumber[i+1];
		}
		while(x->next[i] != NULL && x->next[i]->k < k)
		{
			listNumber[i] = listNumber[i] + x->span[i];
			x = x->next[i];
		}
		p[i] = x;
		i--;
	}
	
}

char * Lookup(struct skipList *list, int m, int k, struct skipList ** p, int * listNumber)
{
	Skip(list, m, k, p, listNumber);
	struct skipList * x = Succ(p[0]);
	return  x->word;
}

void Insert(struct skipList *list, int m, int k, struct skipList ** p, int * listNumber)
{
	Skip(list, m, k, p, listNumber);
	struct skipList * x = InitSkipList(m);
	scanf("%s", x->word);
	x->k = k;
	int r = rand()*2;
	int i = 0;
	while(i < m && r % 2 == 0)
	{
		x->next[i] = p[i]->next[i];
		p[i]->next[i] = x;
		x->span[i] = p[i]->span[i] - listNumber[0] + listNumber[i];
		p[i]->span[i] = listNumber[0] - listNumber[i] + 1;
		i++;
		r = r / 2;
	}
	while(i < m)
	{
		x->next[i] = NULL;
		p[i]->span[i]++;
		i++;
	}
}

void Delete(struct skipList *list, int m, int k, struct skipList ** p, int * listNumber)
{
	Skip(list, m, k, p, listNumber);
	struct skipList * x = Succ(p[0]);
	int i = 0;
	while(i < m && p[i]->next[i] == x)
	{
		p[i]->span[i] += x->span[i] - 1;
		p[i]->next[i] = x->next[i];
		i++;
	}
	while(i < m)
	{
		p[i]->span[i]--;
		i++;
	}
	free(x->span);
	free(x->next);
	free(x);
}

int Rank(struct skipList *list, int m, int k)
{
	int i = m-1;
	int result = 0;
	struct skipList * temp;
	temp = list;
	while(i >= 0)
	{
		while(temp->next[i] != NULL && k > temp->next[i]->k)
		{
			result += temp->span[i];
           		temp = temp->next[i];
		}
		i--;
	}
	return result;
}

int main(void)
{
	struct skipList * list;
	int N;
	scanf("%d", &N);
	int m = log2(N) + 1;
	list = InitSkipList(m);
	int i = 0;
	struct skipList ** p = (struct skipList **)malloc(m*sizeof(struct skipList *));
	int * listNumber = malloc(m*sizeof(int)); 
	char str[6];
	int k = 0;
	struct skipList * forDelete;
	for(i = 0; i < N; i++)
	{
		scanf("%s", str);
		switch(str[0])
		{	
			case 'I':
			{
				scanf("%d", &k);
				Insert(list, m, k, p, listNumber);
				break;
			}
			case 'L': 
			{
				scanf("%d", &k);
				char * temp = Lookup(list,m, k,p, listNumber);
				printf("%s\n", temp);
				break;
			}
			case 'D':
			{
				scanf("%d", &k);
				Delete(list, m, k, p, listNumber);
				break;
			}
			case 'R':
			{
				scanf("%d", &k);
				printf("%d\n", Rank(list, m, k));
				break;
			}
		}
	}
	free(p);
	free(listNumber);
	while(list != NULL)
	{
		forDelete = list->next[0];
		free(list->span);
		free(list->next);
		free(list);
		list = forDelete;
	}
	return 0;
}
