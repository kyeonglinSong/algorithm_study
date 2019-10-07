// 1003 피보나치 함수

#include <iostream>
using namespace std;

int n;
int zero[41];
int one[41];

void dp()
{
	// 초기값 
	zero[0] = 1; one[0] = 0;
	zero[1] = 0; one[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		zero[i] = zero[i - 1] + zero[i - 2];
		one[i] = one[i - 1] + one[i - 2];
	}

	cout << zero[n] << " " << one[n] << endl;
}

int main()
{
	int test;
	cin >> test;

	for (int i = 0; i < test; i++)
	{
		cin >> n;
		dp();
	}

	return 0;
}