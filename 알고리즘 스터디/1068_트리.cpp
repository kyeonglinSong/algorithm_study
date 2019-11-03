#include <iostream>
#include <vector>
using namespace std;

const int MAX = 50;

int n, deleteNode;
pair<int, bool> parent[MAX];
vector<int> ancestor[MAX];

int countLeaf()
{
	// 조상중에 삭제된 노드 있으면 삭제된것이므로leaf아님 표시
	for (int i = 0; i < n; i++)
		for (int j = 0; j < ancestor[i].size(); j++)
			if (ancestor[i][j] == deleteNode)
				parent[i].second = true;

	// 삭제된 노드 제외하고 자식 파악
	for (int i = 0; i < n; i++)
		if (i != deleteNode)
			parent[parent[i].first].second = true;

	// 리프노드 갯수 새기
	int count = 0;
	for (int i = 0; i < n; i++)
		if (parent[i].second == false)
			count++;

	return count;
}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> parent[i].first;
		parent[parent[i].first].second = true;
	}

	// 모든 조상 파악
	for (int i = 0; i < n; i++)
	{
		int curParent = parent[i].first;
		while (curParent != -1)
		{
			ancestor[i].push_back(curParent);
			curParent = parent[curParent].first;
		}
	}
	cin >> deleteNode;
	parent[deleteNode].second = true; // 삭제된 노드는 리프가 아님
	parent[parent[deleteNode].first].second = false; // 삭제된 노드의 부모는 리프임

	cout << countLeaf() << endl;
	return 0;
}