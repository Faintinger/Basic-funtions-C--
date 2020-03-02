#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *substring(char *string, int offset, int size)
{
	char *subS = NULL;
	int i = 0;
	subS = (char *)malloc(size + 1);
	for (i = 0; i < size; i++)
	{
		*(subS + i) = *(string + offset + i);
	}
	*(subS + i) = '\0';
	return subS;
}

char *findSubstring(char *s1, char *s2)
{
	char *auxS1 = NULL;
	char *auxS2 = NULL;
	while (*s1 != '\0')
	{
		auxS1 = s1;
		auxS2 = s2;

		while (*auxS2 != '\0' && *auxS1 == *auxS2)
		{
			auxS1++;
			auxS2++;
		}
		if (*auxS2 == '\0')
		{
			return(s1);
		}
		s1++;
	}
	return NULL;
}

int compare(char* str1, char* str2)
{
	int cstr1 = 0, cstr2 = 0, cstr = 0;
	if (str1 == NULL && str2 == NULL)
		return 1;
	else if (str1 == NULL)
		return 0;
	else if (str2 == NULL)
		return 0;
	else
	{
		while (str1[cstr] != '\0' && str2[cstr] != '\0' && str1[cstr] != NULL && str2[cstr] != NULL)
		{
			if (str1[cstr] != str2[cstr])
				return 0;
			cstr++;
		}
		while (str1[cstr + cstr1] != '\0' && str1[cstr + cstr1] != NULL)
		{
			cstr1++;
		}
		while (str2[cstr + cstr2] != '\0' && str2[cstr + cstr2] != NULL)
		{
			cstr2++;
		}
	}
	return (cstr1 == cstr2);
}

int main()
{
	char key[1];
	//This comment comparation will be false because of the missing \0 char at the end of the array in both methods
	char c[] = "HHHHHHHH";  //{'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H'}; 
	char c2[] = "HHHHHHHH"; //{'H','H','H','H','H','H','H','H'};
	char c3[] = "HHHHHHH";
	char c4[] = "HHHHHH0";
	int result;
	printf("Compare using compare 1 is true for this method --------------------------------\n");
	printf("Compare equals: %d\n", compare(c, c2));
	printf("Compare different lengths: %d\n", compare(c, c3));
	printf("Compare different content: %d\n", compare(c, c4));
	printf("Compare using strcmp 0 is true for this method --------------------------------\n");
	printf("Compare using strcmp equals: %d\n", strcmp(c, c2));
	printf("Compare using strcmp different lengths: %d\n", strcmp(c, c3));
	printf("Compare using strcmp different content: %d\n", strcmp(c, c4));
	scanf_s("%c", &key);
	return 0;
}

