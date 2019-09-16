// 19.09.16   체스판 다시 칠하기

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 987654321;
const int MAX = 50;

int N, M;
string board[MAX];
string whiteFirst[8] = {

		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" }

};
string blackFirst[8] = {

		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" }

};

int blackFirstNum(int y, int x)
{
	int count = 0;

	for (int i = y; i < y + 8; i++)
		for (int j = x; j < x + 8; j++)
			if (board[i][j] != blackFirst[i - y][j - x])
				count++;
	return count;

}

int whiteFirstNum(int y, int x)
{
	int count = 0;
	for (int i = y; i < y + 8; i++)
		for (int j = x; j < x + 8; j++)
			if (board[i][j] != whiteFirst[i - y][j - x])
				count++;
	return count;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> board[i];

	int result = INF;

	for (int i = 0; i+7 < N; i++)
		for (int j = 0; j+7 < M; j++)
			result = min(result, min(blackFirstNum(i,j), whiteFirstNum(i,j)));

	printf("%d\n", result);
	return 0;
}