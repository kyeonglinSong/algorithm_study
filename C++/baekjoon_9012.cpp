// 19.09.12    °ýÈ£

#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

bool Check(string str)
{

	stack<char> st;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
			st.push('(');
		if (str[i] == ')')
		{
			if (st.empty() == 1)
				return false;
			st.pop();
		}
	}
	if (st.empty() == 1)
		return true;
	else
		return false;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;

		if (Check(str))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}