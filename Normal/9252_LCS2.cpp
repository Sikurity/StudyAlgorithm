/**
*	@link	https://www.acmicpc.net/problem/9252
*	@date	2017. 02. 20
*	@author	sikurity
*	@method Longest Common Subsequence Algorithm
*/

#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

#define MAX_SIZE 1000

int LCS[MAX_SIZE + 1][MAX_SIZE + 1];

char first_string[MAX_SIZE + 1];
char second_string[MAX_SIZE + 1];
vector<char> result;

int main(void)
{
	int x, y, ret, size;

	scanf("%s %s", first_string, second_string);

	size_t length_first_string = strlen(first_string);
	size_t length_second_string = strlen(second_string);

	for (int i = 1; i <= length_first_string; i++)
	{
		for (int j = 1; j <= length_second_string; j++)
		{
			if (first_string[i - 1] == second_string[j - 1])
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else
				LCS[i][j] = LCS[i - 1][j] > LCS[i][j - 1] ? LCS[i - 1][j] : LCS[i][j - 1];
		}
	}

	ret = LCS[length_first_string][length_second_string];
	printf("%d\n", ret);

	y = (int)length_first_string;
	x = (int)length_second_string;

	while (y && x && ret)
	{
		if (LCS[y - 1][x] == ret - 1 && LCS[y][x - 1] == ret - 1 && LCS[y - 1][x - 1] == ret - 1 && LCS[y][x] == ret)
			result.push_back(first_string[y - 1]), y--, x--, ret--;
		else if (LCS[y - 1][x] < LCS[y][x - 1])
			x--;
		else
			y--;
	}

	size = (int)result.size();
	for (int i = size - 1; i >= 0; i--)
		printf("%c", result[i]);
	puts("");

	return 0;
}

