/**
*	@link	https://www.acmicpc.net/problem/8896
*	@date	2015. 09. 21 21:01
*	@author	Sikurity
*	@method Simple Simulation
*/

#include <stdio.h>
#include <string.h>

#define MAX_ROBOT_NUM	10
#define MAX_CASE_LENGTH	30

typedef enum BOOL {FALSE, TRUE} BOOL;

int nTestcase;
int nRobot;
int nAnswer;
int nLength;
int nRound;
int remainRobot;

int N;

char sOrders[MAX_ROBOT_NUM][MAX_CASE_LENGTH + 1];
BOOL lossRobot[MAX_ROBOT_NUM];

BOOL algorithm();

int main()
{
	scanf("%d", &nTestcase);

	while( nTestcase-- )
	{
		memset(sOrders, 0, sizeof(sOrders));
		memset(lossRobot, 1, sizeof(lossRobot));

		scanf("%d", &nRobot);

		remainRobot = nRobot;

		for( int k = 0 ; k < nRobot ; k++ )
			scanf("%s", sOrders[k]);

		nRound = nLength = strlen(sOrders[0]);

		N = 0;

		while( algorithm() );

		printf("%d\n", nAnswer);
	}

	return 0;
}

BOOL algorithm()
{
	BOOL R, S, P;
	int result;

	R = FALSE;
	S = FALSE;
	P = FALSE;

	if( nRound-- == 0 )
	{
		nAnswer = 0;
		return FALSE;
	}

	for( int i = 0 ; i < nRobot ; i++ )
	{
		if( lossRobot[i] )
		{
			if( sOrders[i][N] == 'R' )
				R = TRUE;

			else if( sOrders[i][N] == 'S' )
				S = TRUE;

			else if( sOrders[i][N] == 'P' )
				P = TRUE;
		}
	}

	result = R + S + P;

	if( result == 1 || result == 3 )
	{
		N++;
		return TRUE;
	}
	else
	{
		if( result == 2 )
		{
			if( !R )
			{
				for( int i = 0 ; i < nRobot ; i++ )
					if( lossRobot[i] && sOrders[i][N] == 'P' )
					{
						remainRobot--;
						lossRobot[i] = FALSE;
					}

				if( remainRobot == 1)
				{
					for( int i = 0 ; i < nRobot ; i++ )
						if( lossRobot[i] )
						{
							nAnswer = i + 1;
							return FALSE;
						}
				}
			}
			else if( !S )
			{
				for( int i = 0 ; i < nRobot ; i++ )
					if( lossRobot[i] && sOrders[i][N] == 'R' )
					{
						remainRobot--;
						lossRobot[i] = FALSE;
					}

				if( remainRobot == 1)
				{
					for( int i = 0 ; i < nRobot ; i++ )
						if( lossRobot[i] )
						{
							nAnswer = i + 1;
							return FALSE;
						}
				}
			}
			else if( !P )
			{
				for( int i = 0 ; i < nRobot ; i++ )
					if( lossRobot[i] && sOrders[i][N] == 'S' )
					{
						remainRobot--;
						lossRobot[i] = FALSE;
					}

				if( remainRobot == 1)
				{
					for( int i = 0 ; i < nRobot ; i++ )
						if( lossRobot[i] )
						{
							nAnswer = i + 1;
							return FALSE;
						}
				}
			}
		}
	}

	++N;
	return TRUE;
}