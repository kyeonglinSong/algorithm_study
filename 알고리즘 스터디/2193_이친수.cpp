#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 90;

int n;
long long cache[MAX + 1];

long long dp()
{
	cache[1] = cache[2] = 1;
	for (int i = 3; i <= n; i++)
		cache[i] = cache[i - 1] + cache[i - 2];

	return cache[n];
}

int main()
{
	cin >> n;
	cout << dp() << endl;

	return 0;
}