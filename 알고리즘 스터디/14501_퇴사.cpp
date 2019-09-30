// ���

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int day;
int result;
vector<int> term;
vector<int> pay;

void maximumPay(int index, int totalPay)
{
	if (index > day)  // ��� �������� �ʰ��ϸ�
		return;
	if (index == day) // ��� �������ε� ���� ���� �ִ�ġ�϶�
	{
		if (totalPay > result)
			result = totalPay;
		return;
	}
	// ����ϸ� index�� �Ⱓ �߰�, ���� �߰�
	maximumPay(index + term[index], totalPay + pay[index]);
	// ���ϸ� ��¥�� �Ϸ� �߰�
	maximumPay(index + 1, totalPay);
}

int main()
{
	cin >> day;
	for (int i = 0; i < day; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		term.push_back(temp1);
		pay.push_back(temp2);
	}

	maximumPay(0, 0);
	cout << result << endl;
}