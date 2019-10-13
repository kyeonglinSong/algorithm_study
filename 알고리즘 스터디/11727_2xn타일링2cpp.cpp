#include<iostream>
#include <algorithm>
using namespace std;

int n;
int cache[1001];

int dp()
{
	cache[1] = 1;
	cache[2] = 3;
	for (int i = 3; i <= n; i++)
		cache[i] = (cache[i - 2] * 2 + cache[i - 1]) % 10007;
	return cache[n];
}

int main()
{
	cin >> n;
	cout << dp() << endl;
	return 0;
}