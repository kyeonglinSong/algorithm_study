#include <iostream>
using namespace std;

bool areFriends[10][10];
int n;

int countPairs(bool taken[10])
{
	int firstFree = -1;
	for (int i = 0; i < n; i++)
	{
		if (!taken[i])
		{
			firstFree = i;
			break;
		}
	}
	// 다 짝이 있다면
	if (firstFree == -1)
		return 1;
	int result = 0;
	for (int pairWith = firstFree + 1; pairWith < n; pairWith++)
	{
		if (!taken[pairWith] && areFriends[firstFree][pairWith])
		{
			taken[pairWith] = taken[firstFree] = true;
			result += countPairs(taken);
			taken[pairWith] = taken[firstFree] = false; // 다른 경우의 수 찾기위해서 해제
		}
	}
	return result;
}

int main()
{
	int test;
	bool taken[10];
	cin >> test;
	int pairNum;
	for (int i = 0; i < test; i++)
	{
		cin >> n >> pairNum;
		memset(areFriends, false, sizeof(areFriends));
		memset(taken, false, sizeof(taken));

		for (int j = 0; j < pairNum; j++)
		{
			int student1, student2;
			cin >> student1 >> student2;
			areFriends[student1][student2] = areFriends[student2][student1] = true;
		}
		cout << countPairs(taken) << endl;
	}
	return 0;
}
