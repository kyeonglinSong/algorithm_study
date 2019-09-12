// 19.09.12    го╬А д╜

#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	char arr[8][9];

	for (int i = 0; i < 8; i++)
		scanf("%s", &arr[i]);

	int num = 0;

	for(int i=0 ; i<8 ; i++)
		for (int j = 0; j < 8; j++)
			if (arr[i][j] == 'F' && (i + j) % 2 == 0)
				num++;

	cout << num;
	return 0;

}