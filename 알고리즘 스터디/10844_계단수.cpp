#include<iostream>
#include <algorithm>
#incluee <cstring>
using namespace std;

const int MOD = 1000000000;
int cache[10][101];

int dp(int digit, int length)
{
	if (digit < 0 || digit>9)
		return 0;

	int& result = cache[digit][length];
	if (result != -1)
		return result;
	return result = (dp(digit - 1, length - 1) + dp(digit + 1, length - 1)) % MOD;
}

int main()
{
	int n;
	cin >> n;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < 10; i++)
		cache[i][1] = 1;

	int sum = 0;
	for (int i = 1; i <= 9; i++)
	{
		sum += dp(i, n);
		sum %= MOD;
	}
	cout << sum << endl;
	return 0;
}
