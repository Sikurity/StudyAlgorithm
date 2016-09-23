#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>

using namespace std;

int T, N, R;

int main()
{
	
	scanf("%d", &T);

	while( T-- )
	{
		scanf("%d", &N);

		// do something
		if(N == 1)
			cout << 0 << endl;
		else if(N%2 == 1)
			cout << N << endl;
		else
			cout << N/2 << endl;
	}

	return 0;
}