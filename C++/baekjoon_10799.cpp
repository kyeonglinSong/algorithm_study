// 19.09.12    ¼è¸·´ë±â

#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int num=0;
	stack<char> st;
	
	for(int i=0 ; i<str.size() ; i++)
	{
		if (str[i] == '(')
			st.push(str[i]);
		else
		{
			st.pop();
			if (str[i-1] == '(')
				num += st.size();
			else
				num++;
		}
	}
	printf("%d\n", num);
	return 0;
}
