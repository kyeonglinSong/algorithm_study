// 19.09.12    ¿¡µðÅÍ

#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int t;
	cin >> t;
	
	stack<char> left, right;

	for (int i = 0; i < str.size(); i++)
		left.push(str[i]);

	
	for (int j=0 ; j<t ; j++)
	{
		char a;
		cin >> a;

		if (!left.empty() && a == 'L')
		{
			right.push(left.top());
			left.pop();
		}
		else if (!right.empty() && a == 'D')
		{
			left.push(right.top());
			right.pop();
		}
		else if (!left.empty() && a == 'B')
			left.pop();
		else if (a == 'P')
		{
			char b;
			cin >> b;
			left.push(b);
		}
	}
	
	while (!left.empty())
	{
		right.push(left.top());
		left.pop();
	}
	while (!right.empty())
	{
		printf("%c", right.top());
		right.pop();
	}
	
	return 0;
}