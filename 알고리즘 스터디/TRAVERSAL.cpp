#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> slice(const vector<int>& v, int a, int b)
{
	return vector<int>(v.begin() + a, v.begin() + b);
}
void printPostOrder(const vector<int>& preorder, const vector<int>& inorder)
{
	const int N = preorder.size();

	if (preorder.empty())
		return;

	const int root = preorder[0];
	const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	const int R = N - L - 1;
	printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
	printPostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));
	cout << root << " ";

}

int main()
{
	int test;
	cin >> test;

	vector<int> preorder, inorder;
	for (int i = 0; i < test; i++)
	{
		int N;
		cin >> N;

		for (int j = 0; j < N; j++)
		{
			int node;
			cin >> node;
			preorder.push_back(node);
		}

		for (int j = 0; j < N; j++)
		{
			int node;
			cin >> node;
			inorder.push_back(node);
		}
		printPostOrder(preorder, inorder);
		cout << endl;
	}
	return 0;
}