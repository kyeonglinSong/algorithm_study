#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

struct RNG
{
	unsigned seed;
	RNG() : seed(1983) {}
	unsigned next()
	{
		unsigned ret = seed;
		seed = ((seed * 214013u) + 2531011u);
		return ret % 10000 + 1;
	}
};

int k;
int n;

int ITES()
{
	RNG rng;
	queue<int> range;
	int result = 0, rangeSum = 0;
	for (int i = 0; i < n; i++)
	{
		int newSignal = rng.next();
		rangeSum += newSignal;
		range.push(newSignal);

		while (rangeSum > k)
		{
			rangeSum -= range.front();
			range.pop();
		}
		if (rangeSum == k)
			result++;
	}
	return result;
}

int main()
{
	int test;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		cin >> k >> n;
		cout << ITES() << endl;
	}

	return 0;
}