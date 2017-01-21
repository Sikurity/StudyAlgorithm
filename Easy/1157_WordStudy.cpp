/**
*	@link	https://www.acmicpc.net/problem/1157
*	@date	2017. 01. 14 22:48
*	@author	Sikurity
*	@method Take a break
*/
#include <stdio.h>
#include <string.h>

int alphabet[26];

int main()
{
	int i, dup, max;
	char c, result;

	max = 0;
	while((c = fgetc(stdin)) != EOF && c != '\n')
	{
		if('a' <= c && c <= 'z')
			c += 'A' - 'a';
		alphabet[c - 'A']++;

		if(max < alphabet[c - 'A'])
		{
			max = alphabet[c - 'A'];
			result = c;
		}
	}

	dup = 0;
	for(i = 0 ; i < 26 ; i++)
	{
		if(alphabet[i] == max)
			dup++;

		if(dup > 1)
			break;
	}

	if(dup == 1)
		printf("%c", result);
	else
		printf("?");

	return 0;
}