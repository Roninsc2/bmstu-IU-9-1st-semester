//решил упросить задачу, добавив в структуру элемент len.
//Чтоб было более быстрое время выполения

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Elem
{
        struct Elem *next;
        char * words;
	int len;
};

void bsort(struct Elem *list, int len);
struct Elem* InitSingleLinkedList();
void InsertAfter(struct Elem * x, char * words);

int main(void)
{
	struct Elem * list = InitSingleLinkedList();
	char * str = (char *)malloc(100*sizeof(char));
	gets(str);
	struct Elem * x;
	x = list;
	int count = 0;
	int countWords =0;
	const int N = strlen(str); 
	int i = 0;
	int j;
	for(i = 0; i < N; i++)
	{
		count = 0;
		if(str[i] != ' ')
		{	
			countWords++;
			while(i < N)
			{
				count++;
				i++;
				if(str[i] == ' ')
				{
					break;
				}
			}
			char * word = (char *)calloc((count+1),sizeof(char));
			memcpy(word, str+ i - count, count);	
			InsertAfter(x, word);	
			x = x->next;
			free(word);
		}
	}
	bsort(list, countWords);
	x = list->next;
	for(i = 0; i < countWords; i++)
	{
		printf("%s ", x->words);
		x = x->next;
	}
	printf("\n");
	for(i = 0; i < countWords;i++)
	{
		free(list->words);
		x = list;
		list = list->next;
		free(x);
	}
	free(list->words);
	free(list);
	free(str);
	return 0;
}

void InsertAfter(struct Elem * x, char * words)
{
	int len = strlen(words);
	struct Elem * z = x->next;
	struct Elem * y = (struct Elem *)malloc(sizeof(struct Elem));
	int i;
	x->next = y;
	y->words = (char*)calloc((len + 1),sizeof(char));
	y->len = len;
	memcpy(y->words, words, len);
	y->next = z;
	
}

void bsort(struct Elem *list, int len) 
{ 
	struct Elem temp;
	struct Elem * x;
	int i, t = len - 1;
	while(t > 0)
	{
		i = 0;
		t = 0;
		x = list->next;
		while(x->next != list)
		{
			if(x->len > x->next->len)//меняем местами элементы, если нужно
			{
				temp = *x;
                		*x = *temp.next;
                		*temp.next = temp;
                		temp.next->next = x->next;
                		x->next = temp.next;
               		 	t = i;
               		 	x = temp.next;
			}
			else//иначе переходим к следующему элементу
			{
				x = x->next;
			}
			i++;
		}
	}
}

struct Elem * InitSingleLinkedList()
{
	struct Elem * list = (struct Elem*)malloc(sizeof(struct Elem));
	list->next = list;
	list->words = NULL;
	return list;
}
