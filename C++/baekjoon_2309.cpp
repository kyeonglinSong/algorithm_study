// 19.09.15    �ϰ� ������

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int height[10] = { 0 };
	int sum = 0;
	int i, j, flag=0;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &height[i]);
		sum += height[i];
	}

	sort(height, height + 9);

	for (i = 0; i < 8; i++)
	{
		for (j = i + 1; j < 9; j++)
		{
			if (sum - height[i] - height[j] == 100)
			{
				flag++;
				break;
			}
		}
		if (flag == 1)
			break;
	}

	for (int k = 0; k < 9; k++)
		if (k != i && k != j)
			printf("%d\n", height[k]);

	return 0;
}

// 9�� 7�� ��¥�̹Ƿ� ��¥�� Ȯ�� 9c2=36
// ���� for�� ��밡��