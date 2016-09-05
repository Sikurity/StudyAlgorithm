// algorithm2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <stdio.h>

#define MAX_CASE_NUM	30
#define MAX_LENGTH		20

#define BLACK			'#'
#define	WHITE			'.'

#define HEIGHT 0
#define WIDTH 1

/**
*	LINE 1 : case number [0, 30]
*	CASE 1 : height[1, 20], width[0, 20]
*	CASE 2 ~
*	CASE H : #(Black), .(White)
*/

void algorithm(int);
void recursiveCheck(int, int, int, int);

char aGameBoard[MAX_CASE_NUM][MAX_LENGTH][MAX_LENGTH];
char aBoardInfo[MAX_CASE_NUM][2];
int aAnswerTotal[MAX_CASE_NUM];
int results[MAX_CASE_NUM] = {0, };

int nAnswerTotal;

int main()
{
	int i, j, k;
	int caseNum;

	FILE *fp;

	fopen_s(&fp, "input.txt", "r+");

	fscanf(fp, "%d", &caseNum);

	for( i = 0 ; i < caseNum ; i++)
	{
		fscanf(fp, "%d %d\n", &aBoardInfo[i][HEIGHT], &aBoardInfo[i][WIDTH]);
		for( j = 0 ; j < aBoardInfo[i][HEIGHT] ; j++)
		{
			for( k = 0 ; k < aBoardInfo[i][WIDTH] ; k++)
				fscanf(fp, "%c", &aGameBoard[i][j][k]);

			fscanf(fp, "\n");
		}
	}
	
	printf("%d\n", caseNum);

	for( i = 0 ; i < caseNum ; i++)
	{
		printf("%d %d\n", aBoardInfo[i][HEIGHT], aBoardInfo[i][WIDTH]);
		for( j = 0 ; j < aBoardInfo[i][HEIGHT] ; j++ )
		{
			for( k = 0 ; k < aBoardInfo[i][WIDTH] ; k++ )
				printf("%c", aGameBoard[i][j][k]);

			printf("\n");
		}
	}

	fclose(fp);

	for( i = 0 ; i < caseNum ; i++ )
		for( j = 0 ; j < aBoardInfo[i][HEIGHT] ; j++)
			for( k = 0 ; k < aBoardInfo[i][WIDTH] ; k++)
				if( aGameBoard[i][j][k] == WHITE )
					aAnswerTotal[i]++;

	for( i = 0 ; i < caseNum ; i++)
	{
		algorithm(i);
		printf("%d\n", results[i]);
	}

	return 0;
}

void algorithm(int caseNum)
{
	nAnswerTotal = aAnswerTotal[caseNum];

	recursiveCheck(caseNum, 0, 0, 0);
	recursiveCheck(caseNum, 0, 0, 1);
	recursiveCheck(caseNum, 0, 0, 2);
	recursiveCheck(caseNum, 0, 0, 3);
};

void recursiveCheck(int caseNum, int row, int col, int brickCase)
{
	int i, j;
	BOOL isChanged = FALSE;

	int height	= aBoardInfo[caseNum][HEIGHT];
	int width	= aBoardInfo[caseNum][WIDTH];

	while( aGameBoard[caseNum][row][col] == BLACK )
	{
		if( ++col >= width )
		{
			if( ++row >= height )
				return;

			col = 0;
		}
	}

	switch( brickCase )
	{
		case 0 : 
			if
			( 
				(row + 1) != height
				&& (col + 1) != width
				&& aGameBoard[caseNum][row][col] == WHITE
				&& aGameBoard[caseNum][row + 1][col] == WHITE
				&& aGameBoard[caseNum][row][col + 1] == WHITE
			)
			{
				aGameBoard[caseNum][row][col] = BLACK;
				aGameBoard[caseNum][row + 1][col] = BLACK;
				aGameBoard[caseNum][row][col + 1] = BLACK;

				nAnswerTotal -= 3;
				isChanged = TRUE;
					
				break;
			}

			return;
		case 1 : 
			if
			( 
				(row + 1) != height
				&& (col + 1) != width
				&& aGameBoard[caseNum][row][col] == WHITE
				&& aGameBoard[caseNum][row][col + 1] == WHITE
				&& aGameBoard[caseNum][row + 1][col + 1] == WHITE
			)
			{
				aGameBoard[caseNum][row][col] = BLACK;
				aGameBoard[caseNum][row][col + 1] = BLACK;
				aGameBoard[caseNum][row + 1][col + 1] = BLACK;

				nAnswerTotal -= 3;
				isChanged = TRUE;
					
				break;
			}

			return;
		case 2 : 
			if
			( 
				(row + 1) != height
				&& (col + 1) != width
				&& aGameBoard[caseNum][row][col] == WHITE
				&& aGameBoard[caseNum][row + 1][col] == WHITE
				&& aGameBoard[caseNum][row + 1][col + 1] == WHITE
			)
			{
				aGameBoard[caseNum][row][col] = BLACK;
				aGameBoard[caseNum][row + 1][col] = BLACK;
				aGameBoard[caseNum][row + 1][col + 1] = BLACK;

				nAnswerTotal -= 3;
				isChanged = TRUE;
					
				break;
			}

			return;
		case 3 : 
			if
			( 
				(row + 1) != height
				&& (col - 1) != -1
				&& aGameBoard[caseNum][row][col] == WHITE
				&& aGameBoard[caseNum][row + 1][col] == WHITE
				&& aGameBoard[caseNum][row + 1][col - 1] == WHITE
			)
			{
				aGameBoard[caseNum][row][col] = BLACK;
				aGameBoard[caseNum][row + 1][col] = BLACK;
				aGameBoard[caseNum][row + 1][col - 1] = BLACK;

				nAnswerTotal -= 3;
				isChanged = TRUE;
					
				break;
			}

			return;
	}

	/*system("cls");

	for( i = 0 ; i < aBoardInfo[caseNum][0] ; i++ )
	{
		for( j = 0 ; j < aBoardInfo[caseNum][1] ; j++ )
			printf("%c", aGameBoard[caseNum][i][j]);

		printf("\n");
	}*/

	recursiveCheck(caseNum, row, col, 0);
	recursiveCheck(caseNum, row, col, 1);
	recursiveCheck(caseNum, row, col, 2);
	recursiveCheck(caseNum, row, col, 3);

	if( isChanged )
	{
		switch( brickCase )
		{
			case 0 : 
				aGameBoard[caseNum][row][col] = WHITE;
				aGameBoard[caseNum][row + 1][col] = WHITE;
				aGameBoard[caseNum][row][col + 1] = WHITE;

				break;
			case 1 :
				aGameBoard[caseNum][row][col] = WHITE;
				aGameBoard[caseNum][row][col + 1] = WHITE;
				aGameBoard[caseNum][row + 1][col + 1] = WHITE;

				break;
			case 2 :
				aGameBoard[caseNum][row][col] = WHITE;
				aGameBoard[caseNum][row + 1][col] = WHITE;
				aGameBoard[caseNum][row + 1][col + 1] = WHITE;

				break;
			case 3:
				aGameBoard[caseNum][row][col] = WHITE;
				aGameBoard[caseNum][row + 1][col] = WHITE;
				aGameBoard[caseNum][row + 1][col - 1] = WHITE;

				break;
		}

		if( !nAnswerTotal )
			results[caseNum]++;

		nAnswerTotal += 3;
	}

	return;
};