#include<iostream>
#include <algorithm>
using namespace std;

int n;
int RGB[1000][3];
int cache[1000][3];


int dp()
{
	cache[0][0] = RGB[0][0];
	cache[0][1] = RGB[0][1];
	cache[0][2] = RGB[0][2];

	for (int i = 1; i < n; i++)
	{
		cache[i][0] = min(cache[i - 1][1], cache[i - 1][2]) + RGB[i][0];
		cache[i][1] = min(cache[i - 1][0], cache[i - 1][2]) + RGB[i][1];
		cache[i][2] = min(cache[i - 1][0], cache[i - 1][1]) + RGB[i][2];
	}

	return min(cache[n - 1][0], min(cache[n - 1][1], cache[n - 1][2]));
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
	cout << dp() << endl;

	return 0;
}