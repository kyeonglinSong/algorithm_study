#include<iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000;
int n;
int cache[MAX];

int dp()
{
	cache[1] = 1;
	cache[2] = 2;

	for (int i = 3; i <= n; i++)
		cache[i] = (cache[i - 1] + cache[i - 2]) % 1007;

	return cache[n];
}

int main()
{
	cin >> n;
	cout << dp() << endl;

	return 0;
}