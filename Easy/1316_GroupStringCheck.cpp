/**
*	@link	https://www.acmicpc.net/problem/1316
*	@date	2017. 01. 14 22:25
*	@author	Sikurity
*	@method Take a break
*/
#include <stdio.h>
#include <string.h>

bool alphabet[26];
char str[100 + 1];

int main()
{
	int testcase, i, length, result;
	char prev;

	scanf("%d", &testcase);

	result = 0;
	while(testcase--)
	{
		scanf("%s", str);

		memset(alphabet, false, sizeof(alphabet));
		prev = NULL;
		length = strlen(str);
		for(i = 0 ; i < length ; i++)
		{
			if(prev != str[i])
			{
				if(alphabet[str[i] - 'a'])
					break;
				else
					alphabet[str[i] - 'a'] = true;
			}

			prev = str[i];
		}

		if(i == length)
			result++;
	}

	printf("%d", result);

	return 0;
}