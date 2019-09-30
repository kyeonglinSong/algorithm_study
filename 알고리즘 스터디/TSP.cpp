#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
double dist[8][8];

double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength)
{
	if (path.size() == n) // 기저 사례 : 다 돌았을 때
		return currentLength + dist[path[0]][path.back()];  // 다시 마지막 도시에서 처음 도시 거리를 더함
	double ret = numeric_limits<double>::max();
	for (int next = 0; next < n; next++)
	{
		if (visited[next])
			continue;
		int here = path.back();
		path.push_back(next);
		visited[next] = true;
		double cand = shortestPath(path, visited, currentLength + dist[here][next]);
		ret = min(ret, cand);
		visited[next] = false; // 다시 원상복구해줌(다른거 구해야하니까!)
		path.pop_back();
	}
	return ret;
}


int main()
{
	double result; A
		cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> dist[i][j];
	}

	double answer = numeric_limits<double>::max(); // 매우 큰 값!

	for (int i = 0; i < n; i++)
	{
		vector<int> path(1, i);
		vector<bool> visited(n, false);
		visited[i] = true;
		result = shortestPath(path, visited, 0.00000000);
		if (answer > result)
			answer = result;
	}
	cout << answer << endl;
}
