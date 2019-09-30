#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

const int CLOCK = 16, SWITCH = 10, INF = 9999;
int linked[SWITCH][CLOCK] = {

		{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

		{0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},

		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},

		{1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},

		{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},

		{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},

		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},

		{0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},

		{0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

		{0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}

};

// 모든 시계가 12시인지 확인
bool areAligned(const vector<int>& clocks)
{
	for (int i = 0; i < CLOCK; i++)
		if (clocks[i] != 12)
			return false;
	return true;
}

void push(vector<int>& clocks, int swtch)
{
	for (int clock = 0; clock < CLOCK; clock++)
		if (linked[swtch][clock] == 1)
		{
			clocks[clock] += 3;
			if (clocks[clock] == 15)
				clocks[clock] = 3;
		}
}

int solve(vector<int>& clocks, int swtch)
{
	if (swtch == SWITCH)
		return areAligned(clocks) ? 0 : INF;
	int result = INF;
	for (int cnt = 0; cnt < 4; cnt++)
	{
		result = min(result, cnt + solve(clocks, swtch + 1));
		push(clocks, swtch);
	}
	return result;
}

int main()
{
	int test;
	vector<int> clocks(CLOCK); // 시계의 시간 배열
	cin >> test;

	for (int i = 0; i < test; i++)
	{
		for (int j = 0; j < CLOCK; j++)
			cin >> clocks[j];

		int result = solve(clocks, 0);
		if (result == INF)
			cout << -1 << endl;
		else
			cout << result << endl;
	}
	return 0;
}