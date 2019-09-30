// 퇴사

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
	if (index > day)  // 퇴사 다음날을 초과하면
		return;
	if (index == day) // 퇴사 다음날인데 받을 돈이 최대치일때
	{
		if (totalPay > result)
			result = totalPay;
		return;
	}
	// 상담하면 index에 기간 추가, 돈도 추가
	maximumPay(index + term[index], totalPay + pay[index]);
	// 안하면 날짜만 하루 추가
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