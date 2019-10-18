#include <iostream>
#include <algorithm>
using namespace std;

int N;
int str[1000000];
int cache[1000000];

int dp()
{
	cache[0] = str[0];
	for (int i = 1; i < N; i++)
	{
		cache[i] = str[i];
		if (cache[i] < cache[i - 1] + str[i])
			cache[i] = cache[i - 1] + str[i];
	}

	int result = cache[0];
	for (int i = 1; i < N; i++)
		if (result < cache[i])
			result = cache[i];

	return result;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> str[i];
	cout << dp() << endl;

	return 0;
}