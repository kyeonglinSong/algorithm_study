// 19.09.14    �� ��

#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string a, b, c, d, e, f;
	cin >> a >> b >> c >> d;
	e = a + b;
	f = c + d;

	// �ڷ��� �����ϱ�!
	long long  result = stoll(e) + stoll(f);
	cout << result << endl;

	return 0;
}