#define _CRT_NO_SECURE_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX_LEN 5000
#define LENGTH_ALPHABET 26
using namespace std;

int stringLength(char *str)
{
	int ret;

	for(ret = 0 ; str[ret] ; ret++);

	return ret;
}

int T, N1, N2, existColorNum;
int linked[LENGTH_ALPHABET], lengthOfColor[LENGTH_ALPHABET], lastColorPos[LENGTH_ALPHABET];
char S1[MAX_LEN + 1], S2[MAX_LEN + 1];
bool isColorExisted[LENGTH_ALPHABET];

int algorithm(int cur1, int cur2)
{
	int ret;

	if()

	return ret;
}

int main()
{
	int i, j, ret;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%s", S1);
		scanf("%s", S2);

		ret = 0;

		N1 = stringLength(S1);
		N2 = stringLength(S2);

		for(i = 0 ; i < N1 ; i++)
		{
			S1[i] -= '0';
			isColorExisted[S1[i]] = true;
		}
		for(i = 0 ; i < N2 ; i++)
		{
			S2[i] -= '0';
			isColorExisted[S2[i]] = true;
		}

		j = 0;
		for(i = 0 ; i < LENGTH_ALPHABET ; i++)
		{
			if( isColorExisted[i] )
				linked[j++] = i;
		}

		existColorNum = j;
		for(i = 0 ; i < existColorNum ; i++)
		{
			lastColorPos[linked[i]] = -1;
			lengthOfColor[linked[i]] = -1;
		}

		ret = algorithm(0, 0);

		printf("%d\n", ret);
	}

	return 0;
}