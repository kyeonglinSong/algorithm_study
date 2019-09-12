// 19.09.12    ť

#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int main()
{
	int t;
	cin >> t;
	queue<int> q;

	for (int i = 0; i < t; i++)
	{
		string str;
		cin >> str;

		if (str == "push")
		{
			int num;
			cin >> num;
			q.push(num);
		}
		else if (str == "pop")
		{
			if (q.empty())
				printf("%d\n", -1);
			else
			{
				printf("%d\n", q.front());
				q.pop();
			}
		}
		else if (str == "size")
			printf("%d\n", q.size());
		else if (str == "empty")
		{
			if (q.empty())
				printf("%d\n", 1);
			else
				printf("%d\n", 0);
		}
		else if (str == "front")
		{
			if (q.empty())
				printf("%d\n", -1);
			else
				printf("%d\n", q.front());
		}
		else if (str == "back")
		{
			if (q.empty())
				printf("%d\n", -1);
			else
				printf("%d\n", q.back());
		}
	}
	return 0;
}