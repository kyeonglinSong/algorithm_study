// 19.09.14    µ¦

#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;

int main()
{
	int t;
	cin >> t;
	deque<int> dq;

	while (t--)
	{
		string str;
		cin >> str;
		

		if (str == "push_front")
		{
			int num;
			cin >> num;
			dq.push_front(num);
		}
		else if (str == "push_back")
		{
			int num;
			cin >> num;
			dq.push_back(num);
		}
		else if (str == "pop_front")
		{
			if (dq.empty())
				cout << -1 << endl;
			else
			{
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}
		else if (str == "pop_back")
		{
			if (dq.empty())
				cout << -1 << endl;
			else
			{
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}
		else if (str == "size")
		{
			cout << dq.size() << endl;
		}
		else if (str == "empty")
		{
			if (dq.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (str == "front")
		{
			if (dq.empty())
				cout << -1 << endl;
			else
				cout << dq.front() << endl;
		}
		else if (str == "back")
		{
			if (dq.empty())
				cout << -1 << endl;
			else
				cout << dq.back() << endl;
		}
	}
	return 0;
}
