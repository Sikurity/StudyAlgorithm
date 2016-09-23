/**
*	@link	https://www.acmicpc.net/problem/1252
*	@date	2015. 05. 11 22:35
*	@author	Sikurity
*	@method Simple Mathematics
*/

#include <stdio.h>
#include <string.h>

void ReMake(char a[], char b[], int al, int bl)
{
	int diff = al - bl;
	int i;

	if(diff == 0)
		return;
	else if(diff > 0) // b¸¦ ¼öÁ¤
	{
		for(i = bl; i >= 0; i--)
			b[i + diff] = b[i];
		for(i = 0; i < diff; i++)
			b[i] = '0';
	}
	else
	{
		diff = -diff;
		for(i = al; i >= 0; i--)
			a[i + diff] = a[i];
		for(i = 0; i < diff; i++)
			a[i] = '0';
	}
}

char * SumCh(char * a, char * b, int al)
{
	char sumC; int i = 0; char alpha = 0;
	static char ch3[82];
	ch3[al + 1] = 0;

	for(i = al - 1; i >= 0; i--)
	{
		sumC = (a[i] - 48) + (b[i] - 48) + alpha;
		if(sumC == 0 || sumC == 1)
		{
			ch3[i + 1] = sumC + 48; alpha = 0;
		}
		else if(sumC == 2)
		{
			ch3[i + 1] = '0'; alpha = 1;
		}
		else
		{
			ch3[i + 1] = '1'; alpha = 1;
		}
	}
	ch3[0] = alpha + 48;

	return ch3;
}

int main(void)
{
	char ch1[81], ch2[81], ch3[82];
	int al, bl;
	int i = 0, starti = -1;

	scanf("%s %s", ch1, ch2);
	al = strlen(ch1);
	bl = strlen(ch2);

	ReMake(ch1, ch2, al, bl);

	al = strlen(ch1);
	strcpy(ch3, SumCh(ch1, ch2, al));


	while(ch3[i])
	{
		if(ch3[i] == '1')
		{
			starti = i; break;
		}
		i++;
	}

	if(starti == -1)
		printf("0\n");
	else
	{
		while(ch3[starti])
		{
			printf("%d", ch3[starti] - 48);
			starti++;
		}
		printf("\n");
	}

	return 0;
}