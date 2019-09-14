// 19.09.14    알파벳 개수

#include<iostream>
#include<cstdio>
#include <algorithm>
using namespace std;

// argorithm 라이브러리 사용
int main()
{
	string str;
	cin >> str;

	for (int i = 'a'; i <= 'z'; i++)
		cout << count(str.begin(), str.end(), i) << ' ';

	return 0;
}

/*
//처음 푼 것
int main()
{
	string str;
	cin >> str;
	char arr[26] = { 0 };

	for (int i = 0; i < str.size(); i++)
	{
		int a;
		a = int(str[i])-97;
		arr[a]++;
	}

	for (int i = 0; i < 26; i++)
		printf("%d ", arr[i]);

	return 0;
}
*/
