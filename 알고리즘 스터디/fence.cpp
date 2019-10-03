#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int>& h, int left, int right)
{
	if (left == right)  // ���� ��� : ���ڰ� �ϳ��� ���
		return h[left];
	int mid = (left + right) / 2; // ������ �ɰ�
	int result = max(solve(h, left, mid), solve(h, mid + 1, right));
	int low = mid, high = mid + 1;
	int height = min(h[low], h[high]);
	result = max(result, height * 2);
	while (left < low || high < right)
	{
		// �������� ��ũ�� 
		if (high < right && (low == left || h[low - 1] < h[high + 1]))
		{
			high++;
			height = min(height, h[high]);
		}
		else
		{
			low--;
			height = min(height, h[low]);
		}
		result = max(result, height * (high - low + 1));
	}
	return result;
}

int main()
{
	int test, n;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		cin >> n;
		vector<int> h(n, 0);  // �����迭 �ʱ�ȭ
		for (int j = 0; j < n; j++)
			cin >> h[j];

		cout << solve(h, 0, h.size() - 1) << endl; // �糡 �ε����� ����
	}
	return 0;
}
