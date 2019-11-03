#include <iostream>
#include <vector>
using namespace std;

const int MAX = 50;

int n, deleteNode;
pair<int, bool> parent[MAX];
vector<int> ancestor[MAX];

int countLeaf()
{
	// �����߿� ������ ��� ������ �����Ȱ��̹Ƿ�leaf�ƴ� ǥ��
	for (int i = 0; i < n; i++)
		for (int j = 0; j < ancestor[i].size(); j++)
			if (ancestor[i][j] == deleteNode)
				parent[i].second = true;

	// ������ ��� �����ϰ� �ڽ� �ľ�
	for (int i = 0; i < n; i++)
		if (i != deleteNode)
			parent[parent[i].first].second = true;

	// ������� ���� ����
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

	// ��� ���� �ľ�
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
	parent[deleteNode].second = true; // ������ ���� ������ �ƴ�
	parent[parent[deleteNode].first].second = false; // ������ ����� �θ�� ������

	cout << countLeaf() << endl;
	return 0;
}