// 19.09.16    유레카 이론

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> arr;

void calculate()
{
	int n = 1;
	while (n * (n + 1) / 2 < 1000)
	{
		arr.push_back(n * (n + 1) / 2);
		n++;
	}
}
bool triangularNum(int n)
{
	
	for (int i = 0; i < arr.size() ; i++)
		for (int j = 0; j < arr.size() ; j++)
			for (int k = 0; k < arr.size() ; k++)
				if (arr[i] + arr[j] + arr[k] == n)
					return true;

	return false;
}

int main()
{
	int t, k;
	scanf("%d", &t);
	calculate();
	for (int i = 0; i < t; i++)
	{
		scanf("%d",&k);
		if (triangularNum(k))
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}