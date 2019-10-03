// 11729 �ϳ��� ž

#include<iostream>
#include <vector>
#include <algorithm>
#include <cstdio>   // cout ���� �ð��ʰ� ��^^..
using namespace std;

int N;
vector<pair<int, int>> h;

void hanoi(int num, int first, int second, int third)
{
	if (num == 1)
		h.push_back({ first, third });
	else
	{

		hanoi(num - 1, first, third, second);
		h.push_back({ first, third });
		hanoi(num - 1, second, first, third);
	}
}

int main()
{
	cin >> N;

	hanoi(N, 1, 2, 3);

	printf("%d\n", h.size());
	for (int i = 0; i < h.size(); i++)
		printf("%d %d\n", h[i].first, h[i].second);
	return 0;
}