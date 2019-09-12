// 19.09.12    조세퍼스 문제

#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	queue<int> q;

	for (int i = 1; i <= n; i++)
		q.push(i);

	int i = 1;
	cout << "<";
	while(q.size())
	{
		if (q.size() == 1)
		{
			cout << q.front() << ">";
			q.pop();
			break;
		}
		int a;
		a = q.front();
		q.pop();
		if (i == k)
		{
			i = 1;
			printf("%d, ", a);
		}
		else
		{
			q.push(a);
			i++;
		}
	}
}