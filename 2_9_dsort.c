#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//маленьеи латинские буквы кодиируются цифрами: a(97), b(98), ..., y(121), z(122)
//всего их 26, поэтому вспомагательный массив будет длинной в 26 интов


int main(void)
{
        char * str = calloc(1000000, sizeof(char));
	gets(str);

	//сортировка подсчетом сравнений
	int i = 0;
	int j = 0;
	int b = 0;
	int len = strlen(str);
	int * helpStr = calloc(26, sizeof(int));
	for(i = 0; i < len; i++)
	{
		helpStr[(((int)str[i]) - 97)]++;
                //так как str[i], приведенный к int, принимает значения от 97 до 122
                //я вычитаю 97, чтоб без проблем заполнить вспомогатльеный массив
	}
	for(j = 0; j < 26; j++)
	{
		for(i = 0; i < helpStr[j]; i++)
		{
			str[b] = ((char)(j+97));
                        //привожу все обратно, к типу char
			b++;
		}
	}
	//конец сортировки

	
	printf("%s \n", str);
	free(str);	
	free(helpStr);
	return 0;
}
