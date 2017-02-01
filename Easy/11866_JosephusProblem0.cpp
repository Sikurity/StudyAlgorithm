/**
*	@link	https://www.acmicpc.net/problem/11866
*	@date	2017. 01. 31 09:17
*	@author	Sikurity
*	@method Use STL Queue
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

queue<int> Q;

int main()
{
	int M, N;

	scanf("%d %d", &N, &M);

	for( int i = 1 ; i <= N ; i++ )
		Q.push(i);

	printf("<");
	while(Q.empty() == false)
	{
		for(int i = 1 ; i < M ; i++)
		{
			Q.push(Q.front());
			Q.pop();
		}
		printf("%d", Q.front());
		Q.pop();

		if( Q.empty() == false )
			printf(", ");
	}
	printf(">");

	return 0;
}