/**
*	@link	https://www.acmicpc.net/problem/10826
*	@date	2017. 02. 03 15:07
*	@author	Sikurity
*	@method C++ BigInteger Implementation & Get Fibonacci Number By O(lg N) Complexity
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
	if(s[0] == '-') return ans;
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

BigInt BigInteger(char c[]) {
	string s = "";
	for(int i = 0 ; i <= strlen(c) - 1 ; i++)
		s = s + c[i];

	return BigInteger(s);
}

BigInt BigInteger(long long x) {
	string s = "";

	while(x > 0)
		s = char(x % 10 + '0') + s, x /= 10;

	return BigInteger(s);
}

BigInt BigInteger(int x) {
	return BigInteger((long long)x);
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

BigInt operator + (BigInt a, int b) {
	return a + BigInteger(b);
}

BigInt operator * (BigInt a, BigInt b) {
	Set(a);
	Set(b);
	BigInt ans;
	ans.assign(a.size() + b.size(), 0);
	for(int i = 0 ; i <= a.size() - 1 ; i++)
	{
		long long carry = 0ll;
		for(int j = 0; j<b.size() || carry > 0; j++) {
			long long s = ans[i + j] + carry + (long long)a[i] * (j<b.size() ? (long long)b[j] : 0ll);
			ans[i + j] = s%base;
			carry = s / base;
		}
	}
	Set(ans);
	return ans;
}

BigInt operator * (BigInt a, int b) {
	return a * BigInteger(b);
}

void Print(BigInt a) {
	Set(a);
	printf("%d", (a.size() == 0) ? 0 : a.back());
	for(int i = a.size() - 2; i >= 0; i--)
		printf("%09d", a[i]);
	printf("\n");
}

BigInt Fib[10001];

BigInt GetFibonacci(int n)
{
	int next;

	if(Fib[n].size())
		return Fib[n];

	if(n & 1)
	{
		next = (n + 1) / 2;
		return (Fib[n] = GetFibonacci(next) * GetFibonacci(next) + GetFibonacci(next - 1) * GetFibonacci(next - 1));
	}
	else
	{
		next = n / 2;
		return (Fib[n] = (GetFibonacci(next - 1) * 2 + GetFibonacci(next)) * GetFibonacci(next));
	}
}

int main()
{
	int n;

	scanf("%d", &n);

	Fib[0] = BigInteger(0);
	Fib[1] = BigInteger(1);

	Print(GetFibonacci(n));

	return 0;
}