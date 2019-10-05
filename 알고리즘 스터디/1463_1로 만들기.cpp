//1463 1�� �����
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int cache[1000001];


int dp()
{
	// �ʱⰪ
	cache[1] = 0;

	for (int i = 2; i <= n; i++)
	{
		cache[i] = cache[i - 1] + 1;
		// i�� 2�� ������
		if (i % 2 == 0)
			cache[i] = min(cache[i], cache[i / 2] + 1);
		// i�� 3���� ������
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