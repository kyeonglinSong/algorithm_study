// 1992 쿼드 트리

#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
int quad[64][64];

void quadTree(int n, int y, int x)
{
	if (n == 1)  //기저 사례
	{
		cout << quad[y][x];
		return;
	}

	bool zero = true, one = true;
	for (int i = y; i < y + n; i++)
		for (int j = x; j < x + n; j++)
			if (quad[i][j])
				zero = false;
			else
				one = false;

	if (zero)
		cout << 0;
	else if (one)
		cout << 1;
	else
	{
		cout << "(";
		quadTree(n / 2, y, x);
		quadTree(n / 2, y, x + n / 2);
		quadTree(n / 2, y + n / 2, x);
		quadTree(n / 2, y + n / 2, x + n / 2);
		cout << ")";
	}
	return;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < N; j++)
			quad[i][j] = s[j] - '0'; // 왜 이렇게 출력해야지만 될까ㅜㅜ
	}

	quadTree(N, 0, 0);
	cout << endl;
	return 0;
}