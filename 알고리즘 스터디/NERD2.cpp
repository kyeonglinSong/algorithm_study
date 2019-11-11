#include <iostream>
#include <map>
using namespace std;

map<int, int> coords;

bool isDominated(int x, int y)
{
	map<int, int>::iterator it = coords.lower_bound(x);
	if (it == coords.end())
		return false;

	return y < it->second;
}

void removeDominated(int x, int y)
{
	map<int, int>::iterator it = coords.lower_bound(x);

	if (it == coords.begin())
		return;

	--it;
	while (true)
	{
		if (it->second > y)
			break;
		if (it == coords.begin())
		{
			coords.erase(it);
			break;
		}
		else
		{
			map<int, int>::iterator jt = it;
			--jt;
			coords.erase(it);
			it = jt;

		}
	}
}

int registered(int x, int y)
{
	if (isDominated(x, y))
		return coords.size();
	removeDominated(x, y);
	coords[x] = y;
	return coords.size();
}

int main()
{
	int test;
	cin >> test;

	for (int i = 0; i < test; i++)
	{
		int n;
		cin >> n;
		coords.clear();

		int result = 0;
		for (int i = 0; i < n; i++)
		{
			int p, q;
			cin >> p >> q;
			result += registered(p, q);
		}
		cout << result << endl;
	}
}