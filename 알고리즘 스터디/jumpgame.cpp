// JUMPGAME

#include <iostream>
using namespace std;

const int MAX = 100;
int n;
int square[MAX][MAX];
int cache[MAX][MAX];


int dp(int y, int x)
{
	if (y >= n || x >= n)
		return 0;
	if (y == n - 1 && x == n - 1)
		return 1;

	int& ret = cache[y][x];
	if (ret != -1)
		return ret;
	int jumpSize = square[y][x];
	return ret = (dp(y + jumpSize, x) || dp(y, x + jumpSize));

}

int main()
{
	int test;
	cin >> test;

	for (int i = 0; i < test; i++)
	{
		cin >> n;
		memset(cache, -1, sizeof(cache));
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				cin >> square[j][k];

		int result = dp(0, 0);
		if (result != 1)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}

	return 0;
}