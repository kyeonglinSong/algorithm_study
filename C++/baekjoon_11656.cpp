// 19.09.14    ���̻� �迭

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	string arr[1000];
	cin >> str;
	
	for (int i=0; i < str.size(); i++)
		arr[i] = str.substr(i, str.size());

	sort(arr, arr+str.size());

	for (int i = 0; i < str.size(); i++)
		cout << arr[i] << endl;

	return 0;

}

// substr�Լ�, sort�Լ�