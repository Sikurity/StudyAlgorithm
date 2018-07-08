/**
*	@link	https://www.acmicpc.net/problem/7662
*	@date	2016. 09. 25
*	@author	Sikurity
*	@method Use Multi Set
*/

#include <iostream>
#include <cstring>
#include <set>

using namespace std;

multiset<int> S;

int T, N;

int main() {
	char c;
	int n, cnt;
	multiset<int>::iterator iter, end;

	cin >> T;

	while (T--) {
		cin >> N;

		S.clear();
		cnt = 0;

		while (N--) {
			cin >> c >> n;
			if (c == 'I') {
				S.insert(n);
				cnt++;
			}
			else if (cnt && c == 'D') {
				if (cnt == 1 || n == -1) {
					iter = S.begin();
					S.erase(S.equal_range(*iter).first);
					cnt--;
				}
				else if (n == 1) {
					end = S.end(), end--;
					S.erase(S.equal_range(*end).first);
					cnt--;
				}
			}
		}

		if (cnt) {
			iter = S.begin();
			end = S.end();

			if (cnt == 1)
				cout << *iter << " " << *iter << endl;
			else {
				end--;
				cout << *end << " " << *iter << endl;
			}
		}
		else
			cout << "EMPTY" << endl;
	}

	return 0;
}