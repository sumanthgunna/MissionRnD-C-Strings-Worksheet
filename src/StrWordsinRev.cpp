/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <stdio.h>
#include <string.h>
void str_rev(char * input, int i, int j);
void str_words_in_rev(char *input, int len){

	int j = 0;
	for (int i = 0; i < len / 2; i++)
	{
		char a = input[i];
		input[i] = input[len - i - 1];
		input[len - i - 1] = a;
	}
	int prev = 0;
	for (int i = 0; input[i] != '\0'; i++)
	{
		if (input[i] != ' ')
			j++;
		else
		{
			str_rev(input, prev, i - 1);
			while (input[i] == ' ')
				i++;
			prev = i;
			j = i;
		}
	}
	str_rev(input, prev, len - 1);

}
void str_rev(char * input, int i, int j)
{
	int prev = i, next = j;
	while (prev <= next){
		char temp = input[prev];
		input[prev] = input[next];
		input[next] = temp;
		prev++;
		next--;
	}
}
