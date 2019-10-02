
#include <iostream>
#include <string>
using namespace std;


string reverse(string::iterator& it)
{
	// ���� ��ġ ����Ű�� ������
	char head = *(it++);
	if (head == 'b' || head == 'w')
		return string(1, head);
	string first = reverse(it);
	string second = reverse(it);
	string third = reverse(it);
	string forth = reverse(it);
	return string("x") + third + forth + first + second;
}

int main()
{
	int test;
	string quad;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		cin >> quad;
		string::iterator it = quad.begin();
		cout << reverse(it) << endl;
	}
	return 0;
}