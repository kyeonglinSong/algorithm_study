#include <iostream>
#include <stack>
using namespace std;

string str;

bool bracket()
{
	stack<char> st;
	for (int i = 0; i < str.size(); i++)
	{
		char ch = str[i];
		if (ch == '(' || ch == '{' || ch == '[')
			st.push(ch);
		else
		{
			char ch2 = st.top();
			if (ch == ')')
				if (ch2 != '(')
					return false;
			if (ch == '}')
				if (ch2 != '{')
					return false;
			if (ch == ']')
				if (ch2 != '[')
					return false;

			st.pop();
		}
	}
	return true;
}

int main()
{
	int test;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		cin >> str;
		if (!bracket())
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}
