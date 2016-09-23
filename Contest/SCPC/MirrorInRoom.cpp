#include <stdio.h>

typedef struct S
{
	int from;
	int toX;
	int toY;
} S;

int N, T, result;
char M[1000][1001];

S go(S s);

int main()
{
	S s;
	int i, j, t = 0;

	setbuf(stdout, NULL);

	scanf("%d", &T);

	while(t++ < T)
	{
		result = 0;
		scanf("%d", &N);

		for(i = 0 ; i < N ; i++)
			scanf("%s", M[i]);

		for(i = 0 ; i < N ; i++)
			for(j = 0 ; j < N ; j++)
				M[i][j] -= '0';

		s.from = 3;
		s.toX = 0;
		s.toY = 0;

		while(1)
		{
			s = go(s);

			if(s.from == -1)
				break;
		}

		printf("Case #%d\n%d\n", t, result);
	}

	return 0;
}

S go(S s)
{
	int val;

	if(s.toX < 0 || s.toX >= N || s.toY < 0 || s.toY >= N)
	{
		s.from = -1;
		return s;
	}

	val = M[s.toY][s.toX];

	if(val == 0)
	{
		if(s.from == 0)
			s.toY++;
		else if(s.from == 1)
			s.toX--;
		else if(s.from == 2)
			s.toY--;
		else if(s.from == 3)
			s.toX++;
	}
	else if(val == 1)
	{
		M[s.toY][s.toX] = 3;
		result++;

		if(s.from == 0)
		{
			s.from = 1;
			s.toX--;
		}
		else if(s.from == 1)
		{
			s.from = 0;
			s.toY++;
		}
		else if(s.from == 2)
		{
			s.from = 3;
			s.toX++;
		}
		else if(s.from == 3)
		{
			s.from = 2;
			s.toY--;
		}
	}
	else if(val == 2)
	{
		M[s.toY][s.toX] = 4;
		result++;

		if(s.from == 0)
		{
			s.from = 3;
			s.toX++;
		}
		else if(s.from == 1)
		{
			s.from = 2;
			s.toY--;
		}
		else if(s.from == 2)
		{
			s.from = 1;
			s.toX--;
		}
		else if(s.from == 3)
		{
			s.from = 0;
			s.toY++;
		}
	}
	else if(val == 3)
	{
		if(s.from == 0)
		{
			s.from = 1;
			s.toX--;
		}
		else if(s.from == 1)
		{
			s.from = 0;
			s.toY++;
		}
		else if(s.from == 2)
		{
			s.from = 3;
			s.toX++;
		}
		else if(s.from == 3)
		{
			s.from = 2;
			s.toY--;
		}
	}
	else if(val == 4)
	{
		if(s.from == 0)
		{
			s.from = 3;
			s.toX++;
		}
		else if(s.from == 1)
		{
			s.from = 2;
			s.toY--;
		}
		else if(s.from == 2)
		{
			s.from = 1;
			s.toX--;
		}
		else if(s.from == 3)
		{
			s.from = 0;
			s.toY++;
		}
	}

	return s;
}