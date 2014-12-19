#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(char **s, int n);

int main(void)
{
        int n = 0;
        scanf("%d ", &n);
	char * p = 0;
	char ** pMas = malloc(sizeof(char *) *n);
	if(pMas == 0)
	{
		printf("Error ");
		return 1;
	}
	int i = 0;
	for(i = 0; i < n; i++)
	{	
		pMas[i] =  malloc(100*sizeof(char));
		if(pMas[i] == 0)
		{
			printf("Error ");
			return 1;
		}
		gets(pMas[i]);
	}
	p = concat(pMas, n);
	printf("%s \n", p);
	free(p);
	for(i = 0; i < n; i++)
	{
		free(pMas[i]);
	}
	free(pMas);
	return 0;
}

char *concat(char **s, int n) 
{ 
	int i = 0;
	int sumStrlenS = 0;
	for(i = 0; i < n; i++)
	{
		sumStrlenS =sumStrlenS + ((int)strlen(s[i])) + 1;
	}
        char * mas = (char *) malloc((sumStrlenS)*sizeof(char));
	if(mas == 0)
	{
		printf("Error ");
		return 1;
	}
	mas[0] = '\0';
	for(i = 0; i < n; i++)
	{
		strncat(mas, s[i], ((strlen(s[i])) + 1));
	}
	return mas;
}

