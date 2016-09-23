#include <stdio.h>
#include <map>

typedef enum BOOL{ FALSE, TRUE } BOOL;

using namespace std;

unsigned int T, N, tmp;

map<int, BOOL> m;

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
			m[tmp] = m[tmp] ? FALSE : TRUE;
		}

		for(it = m.begin() ; it != m.end() ; it++)
		{
			if(it->second)
				result ^= it->first;
		}

		printf("Case #%u\n%u\n", j++, result);

		m.clear();
	}


	return 0;
}