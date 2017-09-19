#include <stdio.h>
#include <map>

typedef enum BOOL{ FALSE, TRUE } BOOL;

using namespace std;

unsigned int T, N, tmp;

map<int, BOOL> M;

int main()
{
	map<int, BOOL>::iterator it;
	unsigned int result, i, j = 1;

	setbuf(stdout, NULL);

	scanf("%d", &T);

	while(T--)
	{
		result = 0;

		scanf("%u", &N);

		for(i = 0 ; i < N ; i++)
		{
			scanf("%u", &tmp);
			M[tmp] = M[tmp] ? FALSE : TRUE;
		}

		for(it = M.begin() ; it != M.end() ; it++)
		{
			if(it->second)
				result ^= it->first;
		}

		printf("Case #%u\n%u\n", j++, result);

		M.clear();
	}


	return 0;
}