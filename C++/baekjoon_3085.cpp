// 19.09.16   사탕 게임

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 50;
int num;
string arr[MAX];

int candy()
{
	int result = 1;
	
	for (int i = 0; i < num; i++)
	{
		int temp = 1;  // temp변수 초기화때문에 가로세로 각각 지역변수로 선언해줘야함.
		for (int j = 0; j < num - 1; j++)
		{
			//가로줄 확인
			if (arr[i][j] == arr[i][j + 1])
				temp++;
			else
			{
				result = max(result, temp);
				temp = 1;
			}
			result = max(result, temp);
		}
	}
	for (int i = 0; i < num; i++)
	{
		int temp = 1;
		for (int j = 0; j < num - 1; j++)
		{
			//세로줄 확인
			if (arr[j][i] == arr[j + 1][i])
				temp++;
			else
			{
				result = max(result, temp);
				temp = 1;
			}
			result = max(result, temp);
		}
	}

	return result;
}

int main()
{

	cin.tie(0);
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> arr[i];

	int result = 0;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num - 1; j++)
		{
			// 양 옆 바꾸기
			swap(arr[i][j], arr[i][j+1]);
			result = max(result, candy());
			swap(arr[i][j], arr[i][j + 1]); // 다시 바꾸기

			// 위아래 바꾸기
			swap(arr[j][i], arr[j + 1][i]);
			result = max(result, candy());
			swap(arr[j][i], arr[j + 1][i]);
		}

	printf("%d", result);
	return 0;
}