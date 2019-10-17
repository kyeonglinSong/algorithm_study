#include <iostream>
#include <algorithm>
using namespace std;

int N;
int num[500];
int cache[500];

int dp(int start)
{
	int& result = cache[start + 1];
	if (result != -1)
		return result;
	result = 1;
	for (int next = start + 1; next < N; next++)
		if (start == -1 || num[start] < num[next])
			result = max(result, dp(next) + 1);
	return result;
}
int main()
{
	int test;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		cin >> N;
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < N; i++)
			cin >> num[i];

		cout << dp(0) << endl;
	}
	return 0;
}