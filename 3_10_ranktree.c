//либо задача не простая, либо я дибил
//скорее второе :)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elem
{
        long int k;
        char word[10];
        int count;
        struct elem * parent;
	struct elem * left;
	struct elem * right;
};

struct  elem * InitBinarySearchTree(void)
{
	
	struct elem * tree = NULL;
	return tree;
}

struct elem * Minimum(struct  elem * x)
{
	struct elem * y;
	if(x == NULL)
	{
		y = NULL;
	}
	else
	{
		y = x;
		while(y->left != NULL)
		{
			y->count--;
			y = y->left;
		}
	}
	return y;
}

struct  elem * Succ(struct  elem * x)
{
	struct  elem * y;
	if(x->right != NULL)
	{
		y = Minimum(x->right);
	}
	else
	{
		y = x->parent;
		while(y != NULL && x == y->right)
		{
			x = y;
			y = y->parent;
		}
	}
	return y;
}

struct  elem * Descend(struct elem * tree, long int k)
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

struct  elem * DescendforDelete(struct elem * tree, long int k)
{
	struct  elem * x =tree;
	while(x!= NULL && x->k != k)
	{
		x->count--;
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

char * Lookup(struct elem * tree, long int k)
{
	struct  elem * x = Descend(tree, k);
	return x->word;
}

struct elem * Insert(struct elem * tree, long int k)
{
	struct elem * y = (struct elem *)malloc(sizeof(struct elem));	
	struct elem * x;
	y->k = k;
	scanf("%s", y->word);
	y->parent = NULL;
	y->count = 0;
	y->left = NULL;
	y->right = NULL;
	if(tree == NULL)
	{
		tree = y;
	}
	else
	{
		x = tree;
		while(1)
		{
			x->count++;
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
	return tree;
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


struct elem *  Delete(struct elem* tree, long int k)
{
	struct elem * x = DescendforDelete(tree, k);
	struct elem* y;
	if(x->left == NULL && x->right == NULL)
	{
		tree =  ReplaceNode(tree, x, NULL);
	}
	else
	{
		if(x->left == NULL)
		{
			tree = ReplaceNode(tree, x, x->right);
		}
		else
		{
			if(x->right == NULL)
			{
				tree= ReplaceNode(tree, x, x->left);
			}
			else
			{
				y = Succ(x);
				tree = ReplaceNode(tree, y, y->right);
				x->left->parent = y;
				y->left = x->left;
				if(x->right != NULL)
				{
					x->right->parent = y;	
				}
				y->right = x->right;
				y->count = x->count-1;
				tree = ReplaceNode(tree, x, y);	
			}
		}
	}
	free(x);
	return tree;
}

char * SearchByRank(struct elem * tree, int rank)
{
	struct elem * x = tree;
	while(x != NULL)
	{
		if(x->left != NULL)
		{
			if(x->left->count+1 >  rank)
			{
				
				x = x->left;
			}
			else
			{
				if(x->left->count+1 < rank)
				{
						rank -= x->left->count + 2;
						x = x->right;
				}
				else
				{
					return x->word;
				}

			}
		}
		else
		{
			if(rank != 0)
			{
				rank--;
				x = x->right;
			}
			else
			{
				return x->word;
			}
		}
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	struct  elem * tree = InitBinarySearchTree();
	struct  elem * forDelete;
	int i = 0;
	char str[6];
	long int k;
	for(i = 0; i < n; i++)
	{
		scanf("%s", str);
		switch(str[0])
		{
			case 'S':
			{
				scanf( "%ld", &k);
				printf( "%s \n", SearchByRank(tree, k));
				break;
			}
			case 'I':
			{
				scanf("%ld", &k);
				tree = Insert(tree, k);
				break;
			}
			case 'L':
			{
				scanf("%ld", &k);
				char * v = Lookup(tree, k);
				printf("%s \n", v);
				break;
			}
			case 'D':
			{
				scanf("%ld", &k);
				tree = Delete(tree, k);
				break;
			}
		}
	}
	DeleteAll(tree);
	return 0;
}
