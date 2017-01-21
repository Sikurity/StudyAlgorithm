/**
*	@link	https://www.acmicpc.net/problem/2941
*	@date	2017. 01. 14 23:54
*	@author	Sikurity
*	@method Take a break
*/
#include <stdio.h>
#include <string.h>

char str[100 + 1];

int main()
{
	int length, result;

	scanf("%s", str);

	length = strlen(str), result = length;
	for(int i = 0 ; i < length ; i++)
	{
		if(i > 0 && str[i - 1] == 'c' && (str[i] == '=' || str[i] == '-'))
			result--;
		else if(i > 1 && str[i - 2] == 'd' && str[i - 1] == 'z' && str[i] == '=')
			result -= 2;
		else if(i > 0 && str[i - 1] == 'd' && str[i] == '-')
			result--;
		else if(i > 0 && str[i - 1] == 'l' && str[i] == 'j')
			result--;
		else if(i > 0 && str[i - 1] == 'n' && str[i] == 'j')
			result--;
		else if(i > 0 && str[i - 1] == 's' && str[i] == '=')
			result--;
		else if(i > 0 && str[i - 1] == 'z' && str[i] == '=')
			result--;
	}

	printf("%d", result);

	return 0;
}