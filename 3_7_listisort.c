#include "stdio.h"
#include "stdlib.h"
 
struct Elem 
{
        struct Elem *prev, *next;
        int v;
};
 
struct Elem* InitDoubleLinkedList();
void Insert(struct Elem * head, int x);
void Delete(struct Elem *x);
void InsertSort(struct Elem *head);

 
int main(void)
{
        int nel;
	scanf("%d", &nel);
        struct Elem * head = InitDoubleLinkedList();
	int i;
        struct Elem * x;
	x = head->next;
	int temp;
        for (i = 0; i < nel; i++) 
	{
 		scanf("%d", &temp);
                Insert(x, temp);
		x = x->next;
        }
        InsertSort(head);
 	x = head->next;
        for (i = 0; i < nel; i++)
	{
                printf("%d ", x->v);
                x = x->next;
                free(x->prev);
        }
	printf("\n");
        free(x);
        return 0;
}

struct Elem * InitDoubleLinkedList()
{
        struct Elem *list = (struct Elem*)malloc(sizeof(struct Elem));
        list->prev = list;
        list->next = list;
        return list;
}

void Insert(struct Elem * x, int v)
{
        struct Elem *temp1 = x->next; 
	struct Elem *y = (struct Elem*)malloc(sizeof(struct Elem));
        x->next = y;
	y->v = v;
       	y->prev = x;
        y->next = temp1;
        temp1->prev = y;
}
 
void Delete(struct Elem *x)
{
        struct Elem *y, *z;
	z = x->next;
	y = x->prev;
        y->next = z;
        z->prev = y;
        free(x);
}
 
void InsertSort(struct Elem *head)
{
       	struct Elem *x, *y;
       	x = head->next->next;
        while(x != head)
	{
		y = x->prev;
                while(y != head && y->v > x->v)
		{
			y = y->prev;
		}
                Insert(y, x->v);
                x = x->prev;
                Delete(x->next);
		x = x->next;
        }
}
