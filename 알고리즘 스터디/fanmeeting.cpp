#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

void addTo(vector<int>& a, vector<int>& b, int k)
{
	int length = b.size();
	a.resize(max(a.size(), b.size() + k));

	for (int i = 0; i < length; i++)
		a[i + k] += b[i];
}
void subFrom(vector<int>& a, vector<int>& b)
{
	int length = b.size();
	a.resize(max(a.size(), b.size() + 1));

	for (int i = 0; i < length; i++)
		a[i] -= b[i];
}

vector<int> karatsuba(vector<int>& a, vector<int>& b)
{
	int an = a.size(), bn = b.size();

	if (an < bn)
		return karatsuba(b, a);
	if (an == 0 || bn == 0)
		return vector<int>();
	/*  an가 작을 경우 그냥 곱셈을 변경
	if (an <= 50)
		return multiply(a, b);
	*/
	int half = an / 2;
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);

	addTo(a0, a1, 0);
	addTo(b0, b1, 0);

	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	vector<int> result;
	addTo(result, z0, 0);
	addTo(result, z1, half);
	addTo(result, z2, half + half);
	return result;

}

int hugs(string members, string fans)
{
	int n = members.size(), m = fans.size();
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++)
		a[i] = (members[i] == 'M') ? 1 : 0;
	for (int i = 0; i < m; i++)
		b[i] = (fans[i] == 'M') ? 1 : 0;
	vector<int> c = karatsuba(a, b);
	int allHugs = 0;
	for (int i = n - 1; i < m; i++)
		if (c[i] == 0)
			allHugs++;
	return allHugs;

}

int main()
{
	int test;
	string members, fans;

	cin >> test;
	for (int i = 0; i < test; i++)
	{
		cin >> members;
		cin >> fans;
		cout << hugs(members, fans) << endl;
	}
	return 0;
}