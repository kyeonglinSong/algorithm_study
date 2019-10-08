// JUMPGAME

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 500;

int n;
int triangle[MAX + 1][MAX + 1];
int cache[MAX + 1][MAX + 1];


int dp(int height, int width)
{
	int& result = cache[height][width];
	if (result != -1)
		return result;
	if (height == n)
		return result = triangle[height][width];

	return result = max(dp(height + 1, width), dp(height + 1, width + 1)) + triangle[height][width];  // triangle 더해주는거 필요
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> triangle[i][j];

	memset(cache, -1, sizeof(cache));
	cout << dp(1, 1) << endl;

	return 0;
}