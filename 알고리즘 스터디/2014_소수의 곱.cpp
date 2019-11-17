#include <iostream>
#include <map>
#include <queue>
using namespace std;

const int MAX = 100;

long long arr[MAX];
map<long long, long> all;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main()
{
	int k, n;
	cin >> k >> n;

	for (int i = 0; i < k; i++)
		cin >> arr[i];

	pq.push(1);
	long long maxValue = 0;

	for (int i = 0; i < n; i++)
	{
		long long current = pq.top();
		pq.pop();

		for (int j = 0; j < k; j++)
		{
			long long next = current * arr[j];
			if (pq.size() > n && next > maxValue)
				continue;
			if (!all.count(next))
			{
				maxValue = max(maxValue, next);
				all[next] = true;
				pq.push(next);
			}
		}

	}
	cout << pq.top() << "\n";
}