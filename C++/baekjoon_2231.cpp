// 19.09.15    ºÐÇØÇÕ

#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int num = 0;
	int sum = 0;
	scanf("%d", &num);
	
	for (int i = num/2; i <num; i++)
	{
		int temp = i;
		while (temp > 10)
		{
			sum += temp%10;
			temp /= 10;
		}
		sum += temp;

		if (i+sum == num)
		{
			printf("%d\n",i);
			return 0;
		}
		sum = 0;
	}
	printf("0\n");
	return 0;
}