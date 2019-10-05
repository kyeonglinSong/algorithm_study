//1463 1로 만들기
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int cache[1000001];


int dp()
{
	// 초기값
	cache[1] = 0;

	for (int i = 2; i <= n; i++)
	{
		cache[i] = cache[i - 1] + 1;
		// i가 2로 나뉘면
		if (i % 2 == 0)
			cache[i] = min(cache[i], cache[i / 2] + 1);
		// i가 3으로 나뉘면
		if (i % 3 == 0)
			cache[i] = min(cache[i], cache[i / 3] + 1);
	}
	return cache[n];
}


int main()
{
	cin >> n;
	cout << dp() << endl;

	return 0;
}