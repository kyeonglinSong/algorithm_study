#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cache[101][101];
int n;
string wild, str;

int dp(int w, int s)
{
	int& result = cache[w][s];
	if (result != -1)
		return result;

	if (w < wild.size() && s < str.size() && (wild[w] == '?' || wild[w] == str[s]))

		return result = dp(w + 1, s + 1);

	if (w == wild.size() && s == str.size())
		return result = 1;

	if (wild[w] == '*')
	{
		if (dp(w + 1, s) || (s < str.size() && dp(w, s + 1)))
			return result = 1;
	}
	return result = 0;

}

int main()
{
	int test;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		cin >> wild;
		cin >> n;
		vector<string> v;
		for (int j = 0; j < n; j++)
		{
			memset(cache, -1, sizeof(cache));
			cin >> str;
			if (dp(0, 0) == 1)
				v.push_back(str);
		}

		sort(v.begin(), v.end());
		for (int j = 0; j < v.size(); j++)
			cout << v[j] << endl;
		cout << endl;
	}
	return 0;
}