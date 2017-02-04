/**
*	@link	https://www.acmicpc.net/problem/2407
*	@date	2017. 02. 04 01:01
*	@author	Sikurity
*	@method C++ BigInteger Implementation & Get Combination With Pascal triangle Algorithm With Memoization
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

const int base = 1e9;
typedef vector<int> BigInt;

void Set(BigInt &a) {
	while(a.size() > 1 && a.back() == 0) a.pop_back();
}

BigInt BigInteger(string s) {
	BigInt ans;

	if(s.size() == 0) { ans.push_back(0); return ans; }
	while(s.size() % 9 != 0) s = '0' + s;
	for(int i = 0; i < s.size(); i += 9) {
		int v = 0;
		for(int j = i; j<i + 9; j++) v = v * 10 + (s[j] - '0');
		ans.insert(ans.begin(), v);
	}
	Set(ans);
	return ans;
}

BigInt BigInteger(long long x) {
	string s = "";

	while(x > 0)
		s = char(x % 10 + '0') + s, x /= 10;

	return BigInteger(s);
}

BigInt operator + (BigInt a, BigInt b) {
	Set(a);
	Set(b);
	BigInt ans;
	int carry = 0;
	for(int i = 0 ; i <= (a.size() > b.size() ? a.size() : b.size()) - 1 ; i++)
	{
		if(i < a.size()) carry += a[i];
		if(i < b.size()) carry += b[i];
		ans.push_back(carry%base);
		carry /= base;
	}
	if(carry) ans.push_back(carry);
	Set(ans);
	return ans;
}

void Print(BigInt a) {
	Set(a);
	printf("%d", (a.size() == 0) ? 0 : a.back());
	for(int i = a.size() - 2; i >= 0; i--)
		printf("%09d", a[i]);
	printf("\n");
}

BigInt DP[101][101];

BigInt GetComb(int n, int m)
{
	if(DP[n][m].size())
		return DP[n][m];

	return DP[n][m] = ((n == m || m == 0) ? BigInteger(1LL) : GetComb(n - 1, m - 1) + GetComb(n - 1, m));
}

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	Print(GetComb(n, m));

	return 0;
}