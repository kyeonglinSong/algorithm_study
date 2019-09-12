// 19.09.12    Ω∫≈√

#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;


int main()
{
	int t;
	cin >> t;
	stack<int> st;

	for (int i = 0; i < t; i++)
	{
		string s;
		cin >> s;
		
		if (s == "push")
		{
			int num;
			cin >> num;
			st.push(num);
		}
		else if (s == "pop")
		{
			if (st.empty())
				cout << -1 << endl;
			else
			{
				cout << st.top() << endl;
				st.pop();
			}
		}
		else if (s == "top")
		{
			if (st.empty())
				cout << -1 << endl;
			else
				cout << st.top() << endl;
		}
		else if (s == "size")
			cout << st.size() << endl;
		else if (s == "empty")
		{
			if (st.empty())
				cout << 1<<endl;
			else
				cout << 0<<endl;
		}
	}
}