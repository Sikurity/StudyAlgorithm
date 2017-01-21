/**
*	@link	https://www.acmicpc.net/problem/4673
*	@date	2017. 01. 14 20:19
*	@author	Sikurity
*	@method Just Easy
*/
#include <stdio.h>

bool bSelfNumber[10001];

void isSelfNumber(int num, bool flag)
{
	if(num > 10000 || num < 1 || bSelfNumber[num])
		return;

	if(flag)
		bSelfNumber[num] = true;

	isSelfNumber(num + num / 10000 + (num / 1000) % 10 + (num / 100) % 10 + (num / 10) % 10 + num % 10, true);
}

int main()
{
	int i;

	for(i = 1 ; i <= 10000 ; i++)
		isSelfNumber(i, false);

	for(i = 1 ; i <= 10000 ; i++)
	{
		if(bSelfNumber[i] == false)
			printf("%d\n", i);
	}

	return 0;
}