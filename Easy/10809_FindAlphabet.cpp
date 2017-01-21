/**
*	@link	https://www.acmicpc.net/problem/10809
*	@date	2017. 01. 14 22:25
*	@author	Sikurity
*	@method Take a break
*/
#include <stdio.h>
#include <string.h>

char alphabet[26];
char str[100 + 1];
int main()
{
	int length;

	memset(alphabet, -1, sizeof(alphabet));
	scanf("%s", str);

	length = strlen(str);
	for(int i = 0 ; i < length ; i++)
	{
		if(alphabet[str[i] - 'a'] == -1)
			alphabet[str[i] - 'a'] = i;
	}

	for(int i = 0 ; i < 26 ; i++)
		printf("%d ", alphabet[i]);

	return 0;
}