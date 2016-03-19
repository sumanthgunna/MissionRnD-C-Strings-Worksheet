/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>


void number_to_str(float number, char *str, int afterdecimal){
	bool negetive = false;
	int pos = 0;
	if (number < 0){
		negetive = true;
		number = -number;
		str[pos++] = '-';
	}
	int j = 0, i = 0;
	while (j != afterdecimal)
	{
		number = number * 10;
		j++;
	}
	int k = (int)number;
	int p = pos;
	int count = 0;
	while (k != 0)
	{
		str[p++] = k % 10 + '0';
		k = k / 10;
		if (!negetive)
		{
			if (p == afterdecimal)
				str[p++] = '.';
		}
		else
		{
			if (p - 1 == afterdecimal)
				str[p++] = '.';
		}

	}
	str[p] = '\0';
	int prev = pos;
	int next = p - 1;
	while (prev <= next)
	{
		char temp = str[prev];
		str[prev] = str[next];
		str[next] = temp;
		prev++;
		next--;
	}
}
