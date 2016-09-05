#include <stdio.h>
#include <stdlib.h>

#define MAX_LINK_NUM	10
#define MAX_LINK_LENGTH	5
#define MAX_CASE_NUM	30
#define MAX_CLOCK_NUM	16

//typedef enum BOOL{ FALSE, TRUE } BOOL;

static int nCaseNum;
static int nTotalCount;

static int arnResult[MAX_CASE_NUM];
static int arnLinked[MAX_LINK_NUM][MAX_LINK_LENGTH + 1] = 
{
	{0, 1, 2, -1},
	{3, 7, 9, 11, -1},
	{4, 10, 14, 15, -1},
	{0, 4, 5, 6, 7, -1},
	{6, 7, 8, 10, 12, -1},
	{0, 2 , 14, 15, -1},
	{3, 14, 15, -1},
	{4, 5, 7, 14, 15, -1},
	{1, 2, 3, 4, 5, -1},
	{3, 4, 5, 9, 13, -1}
};
static int arnClock[MAX_CASE_NUM][MAX_CLOCK_NUM];

void algorithm(int);
void recursiveCheck(int, int, int);
BOOL checkAnswer(int);

int main()
{
	int i = 0;
	int j = 0;
	FILE *fp;

	fp = fopen("input.txt", "r+");

	fscanf(fp, "%d", &nCaseNum);

	for( i = 0 ; i < nCaseNum ; i++ )
		for( j = 0 ; j < MAX_CLOCK_NUM ; j++ )
			fscanf(fp, "%d_", &arnClock[i][j]);

	for( i = 0 ; i < nCaseNum ; i++ )
		algorithm(i);

	printf("%d\n", nCaseNum);

	for( i = 0 ; i < nCaseNum ; i++ )
	{
		for( j = 0 ; j < MAX_CLOCK_NUM ; j++ )
		{
			printf("%d", arnClock[i][j]);

			if( j != MAX_CLOCK_NUM - 1)
				printf(" ");
			else
				printf("\n");
		}
	}

	for( i = 0 ; i < nCaseNum ; i++ )
		printf("%d\n", arnResult[i] == INT_MAX ? -1 : arnResult[i]);

	fclose(fp);

	return 0;
}

void algorithm(int caseNum)
{
	nTotalCount = 0;
	arnResult[caseNum] = INT_MAX;
		
	recursiveCheck(caseNum, 0, 0);
	recursiveCheck(caseNum, 0, 1);
	recursiveCheck(caseNum, 0, 2);
	recursiveCheck(caseNum, 0, 3);
}

void recursiveCheck(int caseNum, int linkNum, int repeatNum)
{
	int i;

	if( linkNum >= MAX_LINK_NUM || arnResult[caseNum] <= nTotalCount )
		return;

	nTotalCount += repeatNum;

	for( i = 0 ; i < MAX_LINK_LENGTH ; i++ )
	{
		if( arnLinked[linkNum][i] == -1 )
			break;

		arnClock[caseNum][arnLinked[linkNum][i]] += (3 * repeatNum);
	}

	/*system("cls");

	printf("%d\n", nTotalCount);
	for( i = 0 ; i < MAX_CLOCK_NUM ; i++ )
	{
		printf("%d", arnClock[caseNum][i]);
		if( i != MAX_CLOCK_NUM - 1)
			printf(" ");
		else
			printf("\n");
	}

	Sleep(100);*/

	if( checkAnswer(caseNum) )
		arnResult[caseNum] = nTotalCount;

	recursiveCheck(caseNum, linkNum + 1, 0);
	recursiveCheck(caseNum, linkNum + 1, 1);
	recursiveCheck(caseNum, linkNum + 1, 2);
	recursiveCheck(caseNum, linkNum + 1, 3);

	for( i = 0 ; i < MAX_LINK_LENGTH ; i++ )
	{
		if( arnLinked[linkNum][i] == -1 )
			break;

		arnClock[caseNum][arnLinked[linkNum][i]] -= (3 * repeatNum);
	}
	
	nTotalCount -= repeatNum;

	return;
}

BOOL checkAnswer(int caseNum)
{
	int i;

	for( i = 0 ; i < MAX_CLOCK_NUM ; i++ )
		if( arnClock[caseNum][i] % 12 )
			return FALSE;

	return TRUE;
}