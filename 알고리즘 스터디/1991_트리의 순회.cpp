#include <iostream>
using namespace std;

struct node {
	char left;
	char right;
};
struct node tree[100];

void preorder(char root)
{
	if (root == '.')
		return;
	else
	{
		cout << root;
		preorder(tree[root].left);
		preorder(tree[root].right);
	}
}

void inorder(char root)
{
	if (root == '.')
		return;
	else
	{
		inorder(tree[root].left);
		cout << root;
		inorder(tree[root].right);
	}
}

void postorder(char root)
{
	if (root == '.')
		return;
	else
	{
		postorder(tree[root].left);
		postorder(tree[root].right);
		cout << root;
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char value, left, right;
		cin >> value >> left >> right;

		tree[value].left = left;
		tree[value].right = right;
	}

	preorder('A');
	cout << endl;
	inorder('A');
	cout << endl;
	postorder('A');
	cout << endl;

	return 0;
}