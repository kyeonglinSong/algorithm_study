#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<string> name(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> name[i];

	vector<pair<string, int>> sortVector(n);
	for (int i = 0; i < n; i++)
	{
		sortVector[i].first = name[i + 1];
		sortVector[i].second = i + 1;
	}
	sort(sortVector.begin(), sortVector.end());

	for (int i = 0; i < m; i++)
	{
		string str;
		cin >> str;

		// 1. 인덱스의 경우
		if (str[0] >= '0' && str[0] <= '9')
		{
			int index = 0;
			for (int j = 0; j < str.length; j++)
			{
				index += (int)(str[j] - '0');
				index *= 10;
			}
			index /= 10;
			cout << name[index] << endl;
		}
		else // 2. 이름이 입력되는 경우 - 이분탐색
		{
			int low = 0, high = n - 1;
			while (low <= high)
			{
				int mid = (low + high) / 2;

				if (sortVector[mid].first == str)
				{
					cout << sortVector[mid].second << endl;
					break;
				}
				else if (sortVector[mid].first < str)
					low = mid + 1;
				else
					high = mid - 1;
			}
		}
	}

}