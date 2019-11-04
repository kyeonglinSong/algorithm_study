#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100;

struct TreeNode
{
	vector<TreeNode*> children;
};

int longest;
int N, y[MAX], x[MAX], radius[MAX];

int height(TreeNode* root)
{
	vector<int> heights;
	for (int i = 0; i < root->children.size(); i++)
		heights.push_back(height(root->children[i]));
	if (heights.empty())
		return 0;
	sort(heights.begin(), heights.end());

	if (heights.size() >= 2)
		longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() + 1]);
	return heights.back() + 1;
}

int solve(TreeNode* root)
{
	longest = 0;
	int h = height(root);
	return max(longest, h);
}

int sqr(int x)
{
	return x * x;
}

int sqrdist(int a, int b)
{
	return sqr(y[a] - y[b]) + sqr(x[a] - x[b]);
}

bool encloses(int a, int b)
{
	return radius[a] > radius[b] && sqrdist(a, b) < sqr(radius[a] - radius[b]);

}

bool isChild(int parent, int child)
{
	if (!encloses(parent, child))
		return false;

	for (int i = 0; i < N; i++)
		if (i != parent && i != child && encloses(parent, i) && encloses(i, child))
			return false;
	return true;
}

TreeNode* getTree(int root)
{
	TreeNode* result = new TreeNode();
	for (int ch = 0; ch < N; ch++)
		if (isChild(root, ch))
			result->children.push_back(getTree(ch));
	return result;
}

int main()
{
	int test_case;
	cin >> test_case;

	for (int i = 0; i < test_case; i++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> x[i] >> y[i] >> radius[i];
		TreeNode* T = getTree(0);
		cout << solve(T) << endl;

	}
	return 0;
}