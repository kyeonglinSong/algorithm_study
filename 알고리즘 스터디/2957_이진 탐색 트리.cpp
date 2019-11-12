#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	long long c = 0;
	map<int, int> depth;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if (i == 0)
		{
			depth[num] = 1;
			cout << c << endl;
			continue;
		}

		auto iterator = depth.upper_bound(num);
		int height = 0;

		if (iterator != depth.end())
			height = iterator->second;

		if (iterator != depth.begin())
		{
			iterator--;
			height = max(height, iterator->second);
		}
		c += height;

		cout << c << endl;
		depth[num] = height + 1;
	}
	return 0;
}