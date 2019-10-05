// 2579 ��� ������
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int cache[300], stair[300];

int dp()
{
	// �ʱⰪ
	cache[0] = stair[0];
	cache[1] = stair[0] + stair[1];
	cache[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

	for (int i = 3; i < n; i++)
		cache[i] = max(cache[i-3]+stair[i-1]+stair[i], cache[i-2]+stair[i]);

	return cache[n-1];
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> stair[i];
	cout << dp() << endl;

	return 0;
}