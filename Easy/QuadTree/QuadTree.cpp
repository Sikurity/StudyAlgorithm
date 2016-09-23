#include <cstdio>
#include <string>

#define MAX_CASE_NUM	50
#define MAX_STR_LENG	1000

using namespace std;

static int	nCaseNum;
static char arsQuadTree[MAX_CASE_NUM][MAX_STR_LENG];

void	algorithm(int);
string	reverse(string::iterator &it);

int main()
{
	FILE *fp;
	int i;

	fp = fopen("input.txt", "r+");

	fscanf(fp, "%d", &nCaseNum);

	for( i = 0 ; i < nCaseNum ; i++ )
		fscanf(fp, "%s", arsQuadTree[i]);

	for( i = 0 ; i < nCaseNum ; i++ )
		algorithm(i);

	fclose(fp);

	return 0;
}

void algorithm(int caseNum)
{
	string str = string(arsQuadTree[caseNum]);
	string::iterator it = str.begin();

	printf(reverse(it).c_str());
	printf("\n");
}

string reverse(string::iterator &it)
{
	char head = *it;
	it++;

	if( head == 'b' || head == 'w' )
		return string(1, head);

	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string bottomLeft = reverse(it);
	string bottomRight = reverse(it);

	return string("x") + bottomLeft + bottomRight + upperLeft + upperRight;
}