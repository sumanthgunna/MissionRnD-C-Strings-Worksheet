/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31

void str_cpy(char * cpy1, char * cpy2)
{
	int i = 0;
	for (i = 0; cpy2[i] != '\0'; i++)
	{
		cpy1[i] = cpy2[i];
	}
	cpy1[i] = '\0';
}
bool str_cmp(char * word1, char * word2)
{
	for (int i = 0; word1[i] != '\0'; i++)
	{
		if (word1[i] != word2[i])
			return false;
	}
	return true;
}


bool compare(char * temp, char * sent2)
{
	if (temp[0] == '\0')
		return false;
	int n = 0;
	char * temp2;
	temp2 = (char *)malloc(sizeof(char)* 20);
	for (int j = 0; sent2[j] != '\0'; j++)
	{
		if (sent2[j] != ' ')
			temp2[n++] = sent2[j];
		else
		{
			temp2[n] = '\0';
			if (str_cmp(temp, temp2))
				return true;
			while (sent2[j - 1] == ' ')
				j++;
			n = 0;
		}
	}
	temp2[n] = '\0';
	if (str_cmp(temp, temp2))
		return true;
	return false;
}

char ** commonWords(char * str1, char * str2)
{
	char ** result = (char **)malloc(sizeof(char)* 31);
	for (int i = 0; i < 31; i++)
		result[i] = (char *)malloc(sizeof(char)* 31);
	int pos = 0;
	int m = 0, n = 0;
	if (str1 == NULL || str2 == NULL)
		return NULL;

	char * temp1;
	temp1 = (char *)malloc(sizeof(char)* 20);
	for (int i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] != ' ')
			temp1[m++] = str1[i];
		else{
			temp1[m] = '\0';
			if (compare(temp1, str2))
				str_cpy(result[pos++], temp1);
			while (str1[i - 1] == ' ')
				i++;
			m = 0;
		}
	}
	temp1[m] = '\0';
	if (compare(temp1, str2))
		str_cpy(result[pos++], temp1);
	result[pos] = NULL;
	return result;
}