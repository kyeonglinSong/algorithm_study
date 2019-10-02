#include<iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> v;

void Hanoi(int num, int first, int second, int third)
{
	if (num == 1) // �� ���� 1 -> 3
		v.push_back({ first, third });
	else
	{
		Hanoi(num - 1, first, third, second);  // �� ���� ���� ��� 1 -> 2
		v.push_back({ first, third }); // �ű�� ����
		Hanoi(num - 1, second, first, third); //�����͵� 2 -> 3
	}
}

int main(void)

{
	cin >> N;
	Hanoi(N, 1, 2, 3);
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second << endl;
	return 0;
}
