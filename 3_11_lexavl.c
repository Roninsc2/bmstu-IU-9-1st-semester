#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elem
{
        int value;
	unsigned int k;
	int balance;
	struct elem * parent;
	struct elem * left;
	struct elem * right;
};

struct  elem * Descend(struct elem * tree, unsigned int k)
{
	struct  elem * x =tree;
	while(x!= NULL && x->k != k)
	{
		if(k < x->k)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	return x;
	
}

int Lookup(struct elem * tree, unsigned int k)
{
	struct  elem * x;
	x = Descend(tree, k);
	if(x == NULL || k != x->k)
	{
		return -1;
	}
	else
	{
		return x->value;
	}
}

struct elem * ReplaceNode(struct elem* tree, struct elem* x, struct elem* y)
{
	if(tree == x)
	{
		tree = y;
		if(y != NULL)
		{
			y->parent = NULL;
		}
	}
	else
	{
		struct elem * p = x->parent;
		if(y != NULL)
		{
			y->parent = p;
		}
		if(p->left == x)
		{
			p->left = y;
		}
		else
		{
			p->right = y;
		}
	}
	return tree;
}

struct elem * RotateLeft(struct elem * tree, struct elem * x)
{
	struct elem * y = x->right;
	if(y == NULL)
	{
		printf("ERROR IN ROTATE LEFT");
		return tree;
	}
	tree = ReplaceNode(tree, x, y);
	struct elem * b = y->left;
	if(b != NULL)
	{
		b->parent = x;
	}
	x->right = b;
	x->parent = y;
	y->left = x;
	x->balance--;
	if(y->balance > 0)
	{
		x->balance -= y->balance;
	}
	y->balance--;
	if(x->balance < 0)
	{
		y->balance += x->balance;
	}
	return tree;
}

struct elem * RotateRight(struct elem * tree, struct elem * x)
{
	struct elem * y = x->left;
	if(y == NULL)
	{
		printf("ERROR IN ROTATE RIGHT");
		return tree;
	}
	tree = ReplaceNode(tree, x, y);
	struct elem * b = y->right;
	if(b != NULL)
	{
		b->parent = x;
	}
	x->left = b;
	x->parent = y;
	y->right = x;
	x->balance++;
	if(y->balance < 0)
	{
		x->balance -= y->balance;
	}
	y->balance++;
	if(x->balance > 0)
	{
		y->balance += x->balance;
	}
	return tree;
}


struct elem * Insert(struct elem ** tree, unsigned int k, unsigned int v)
{
	struct elem * y = (struct elem *)malloc(sizeof(struct elem));	
	struct elem * x;
	y->k = k;
	y->value = v;
	y->parent = NULL;
	y->left = NULL;
	y->right = NULL;
	if((*tree) == NULL)
	{
		(*tree) = y;
	}
	else
	{
		x = (*tree);
		while(1)
		{
			if(k < x->k)
			{
				if(x->left == NULL)
				{
					x->left = y;
					y->parent = x;
					break;
				}
				x = x->left;
			}
			else
			{
				if(x->right == NULL)
				{
					x->right = y;
					y->parent = x;
					break;
				}
				x = x->right;
			}
			
		}
	}
	return y;
}

struct elem * InsertAVL(struct elem * tree, unsigned int k, unsigned int v)
{
	struct elem * a = Insert(&tree, k, v);
	struct elem * x;
	a->balance = 0;
	while(1)
	{
		x = a->parent;
		if(x == NULL)
		{
			break;
		}
		if(a == x->left)
		{
			x->balance--;
			if(x->balance == 0)
			{
				break;
			}
			if(x->balance == -2)
			{
				if(a->balance == 1)
				{
					tree = RotateLeft(tree, a);
				}
				tree = RotateRight(tree, x);
				break;
			}	
		}
		else
		{
			x->balance++;
			if(x->balance == 0)
			{
				break;
			}
			if(x->balance == 2)
			{
				if(a->balance == -1)
				{
					tree = RotateRight(tree, a);
				}
				tree = RotateLeft(tree, x);
				break;
			}	
		}
		a = x;
	}
	return tree;
}

void DeleteAll(struct elem* tree)
{
	struct elem *temp;
   	if (tree != NULL)
	{
        	DeleteAll(tree->left);
        	temp = tree->right;
        	free(tree);
        	DeleteAll(temp);
    	}
}

unsigned int HashLy(const char * str)
{

	unsigned int hash = 0;

	for(; *str; str++)
	{
		hash = (hash * 1664525) + (unsigned char)(*str) + 1013904223;
	}
	
	return hash;

}

int SpecTag(char a)
{
	switch (a)
	{
		case '+':
		{
			return 0;
		}
		case '-':
		{
			return 1;
		}
		case '*':
		{
			return 2;
		}
		case '/':
		{
			return 3;
		}
		case '(':
		{
			return 4;
		}
		case ')':
		{
			return 5;
		}
		default:
		{
			return -1;
		}
	}
}


int main(void)
{
	int n;
	scanf("%d ", &n);
	char * arr = (char *)malloc((n+1)*sizeof(char));
	struct  elem * tree = NULL;
	int i = 0;
	int j = 0;
	int tempSPEC = -1;
	unsigned int resultIDENT = -1;
	int number = 0;
	unsigned int k = 0;
	char * word = malloc(15*sizeof(char));
	memset(word, '\0', 15);
	int countIDENT = 0;
	gets(arr);
	int len = strlen(arr);
	for(i = 0; i < len;i++)
	{
		if(arr[i] != ' ')
		{	
			tempSPEC = SpecTag(arr[i]);
			if(tempSPEC != -1)
			{
				if(word[0] != '\0')
				{
					if(((int)word[0]) < 48 || ((int)word[0]) > 57)
					{
						k = HashLy(word);	
						resultIDENT = Lookup(tree, k);
						if(resultIDENT != -1)
						{
							printf("IDENT %d \n", resultIDENT);
						}
						else
						{
							printf("IDENT %d \n", countIDENT);
							tree = InsertAVL(tree, k, countIDENT);
							countIDENT++;
						}
							
					}
					else
					{
						number = atoi(word);
						printf("CONST %d \n", number);
					}
					memset(word, '\0', 15);
					j = 0;
				}
				printf("SPEC %d \n", tempSPEC);	
			}
			else
			{
				word[j] = arr[i];
				j++;
			}
			tempSPEC = -1;
		}
		else
		{
			if(word[0] != '\0')
			{
				if(((int)word[0]) < 48 || ((int)word[0]) > 57)
				{
					k = HashLy(word);
					resultIDENT = Lookup(tree, k);
					if(resultIDENT != -1)
					{
						printf("IDENT %d \n", resultIDENT);
					}
					else
					{
						printf("IDENT %d \n", countIDENT);
						tree = InsertAVL(tree, k, countIDENT);
						countIDENT++;
					}
							
				}
				else
				{
					number = atoi(word);
					printf("CONST %d \n", number);
				}
				memset(word, '\0', 15);
				j = 0;
			}
		}
	}
	if(word[0] != '\0')
	{
		if(((int)word[0]) < 48 || ((int)word[0]) > 57)
		{
			k = HashLy(word);
			resultIDENT = Lookup(tree, k);
			if(resultIDENT != -1)
			{
				printf("IDENT %d \n", resultIDENT);
			}
			else
			{
				printf("IDENT %d \n", countIDENT);
				tree = InsertAVL(tree, k, countIDENT);
				countIDENT++;
			}
							
		}
		else
		{
			number = atoi(word);
			printf("CONST %d \n", number);
		}
	}
	free(arr);
	free(word);
	DeleteAll(tree);
	return 0;
}
