/**
*	@link	https://www.acmicpc.net/problem/4256
*	@date	2015. 09. 25 19:44
*	@author	Sikurity
*	@method Make Tree Using Preorder, Inorder Tree Data
*/

#include <iostream>
#include <cstring>

#define MAX_LEN 1000

using namespace std;

int T, N;
int P[MAX_LEN + 1];
int R[MAX_LEN + 1];

class Tree
{
public:
	int index;

	Tree *l;
	Tree *r;

	Tree(int index)
	{
		l = NULL;
		r = NULL;
		this->index = index;
	}

	Tree *MakeLeft(int index)
	{
		if( this->l == NULL )
			this->l = new Tree(index);

		return this->l;
	}

	Tree *MakeRight(int index)
	{
		if(this->r == NULL)
			this->r = new Tree(index);

		return this->r;
	}

	Tree *Clear()
	{
		if( l )
			delete l->Clear();
		if( r )
			delete r->Clear();

		cout << this->index << ' ';

		return this;
	}
};

int main()
{
	Tree *tree;
	Tree *arr[MAX_LEN + 1];
	int i, t, cur;

	cin >> T;

	while( T-- )
	{
		cin >> N;

		memset(arr, NULL, sizeof(arr));

		for(i = 1 ; i <= N ; i++)
			cin >> P[i];
	
		for(i = 1 ; i <= N ; i++)
		{
			cin >> t;
			R[t] = i;
		}

		for(i = 1 ; i <= N ; i++)
		{
			if(i > 1)
			{
				cur = P[1];
				while(true)
				{
					if(R[P[i]] - R[cur] >= 0)
					{
						if(arr[cur]->r)
							cur = arr[cur]->r->index;
						else
						{
							arr[P[i]] = arr[cur]->MakeRight(P[i]);
							break;
						}
					}
					else
					{
						if(arr[cur]->l)
							cur = arr[cur]->l->index;
						else
						{
							arr[P[i]] = arr[cur]->MakeLeft(P[i]);
							break;
						}
					}
				}
			}
			else
			{
				tree = new Tree(P[1]);
				arr[P[1]] = tree;
			}
		}

		delete tree->Clear();
		cout << endl;
	}

	return 0;
}