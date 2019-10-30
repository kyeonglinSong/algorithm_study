#include <iostream>
#include <queue>
using namespace std;


void getSequence(int N, int M)
{
	queue<pair<int, int>> q;
	priority_queue<int> pq;

	for (int j = 0; j < N; j++)
	{
		int a;
		cin >> a;
		q.push({ j, a });
		pq.push(a);
	}

	int count = 0;
	while (!q.empty())
	{
		int nowidx = q.front().first;
		int nowval = q.front().second;
		q.pop();

		if (pq.top() == nowval)
		{
			pq.pop();
			count++;
			if (nowidx == M)
			{
				cout << count << endl;
				break;
			}
		}
		else
			q.push({ nowidx, nowval });
	}
}

int main()
{
	int test;
	cin >> test;

	for (int i = 0; i < test; i++)
	{
		int N, M;
		cin >> N >> M;
		getSequence(N, M);
	}

	return 0;
}