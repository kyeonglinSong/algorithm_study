#include <iostream>
#include <algorithm>
using namespace std;

int N;
int triangle[100][100];
int cache[100][100];

int dp(int height, int num)
{
	if (height > N - 1)
		return triangle[height][num];

	int& result = cache[height][num];
	if (result != -1)
		return result;
	return result = max(dp(height + 1, num), dp(height + 1, num + 1)) + triangle[height][num];

}

int main()
{
	int test;
	cin >> test;

	for (int k = 0; k < test; k++)
	{
		cin >> N;
		memset(cache, -1, sizeof(cache));

		for (int i = 0; i < N; i++)
			for (int j = 0; j < i + 1; j++)
				cin >> triangle[i][j];

		cout << dp(0, 0) << endl;
	}
	return 0;
}