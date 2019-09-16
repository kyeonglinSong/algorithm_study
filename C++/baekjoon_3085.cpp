// 19.09.16   ���� ����

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
		int temp = 1;  // temp���� �ʱ�ȭ������ ���μ��� ���� ���������� �����������.
		for (int j = 0; j < num - 1; j++)
		{
			//������ Ȯ��
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
			//������ Ȯ��
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
			// �� �� �ٲٱ�
			swap(arr[i][j], arr[i][j+1]);
			result = max(result, candy());
			swap(arr[i][j], arr[i][j + 1]); // �ٽ� �ٲٱ�

			// ���Ʒ� �ٲٱ�
			swap(arr[j][i], arr[j + 1][i]);
			result = max(result, candy());
			swap(arr[j][i], arr[j + 1][i]);
		}

	printf("%d", result);
	return 0;
}