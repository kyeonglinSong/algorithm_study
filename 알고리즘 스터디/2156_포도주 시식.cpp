#include<iostream>
#include <algorithm>
using namespace std;

int n;
int wine[100001];
int cache[10001];


int dp()
{
	cache[1] = wine[1];
	cache[2] = wine[1] + wine[2];

	for (int i = 3; i <= n; i++)
	{
		cache[i] = max(cache[i - 2] + wine[i], cache[i - 3] + wine[i - 1] + wine[i]);
		cache[i] = max(cache[i - 1], cache[i]);
	}

	return cache[n];
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> wine[i];
	cout << dp() << endl;

	return 0;
}