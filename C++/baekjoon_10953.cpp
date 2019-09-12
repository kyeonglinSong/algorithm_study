rh// 19.09.12    A+B -6

#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int a, b;
		scanf("%d,%d" ,&a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}