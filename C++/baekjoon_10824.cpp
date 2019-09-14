// 19.09.14    네 수

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

	// 자료형 주의하기!
	long long  result = stoll(e) + stoll(f);
	cout << result << endl;

	return 0;
}