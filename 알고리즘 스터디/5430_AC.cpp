#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	int test;
	cin >> test;

	for (int i = 0; i < test; i++)
	{
		string function, arr;
		int n;

		cin >> function;
		cin >> n;
		cin >> arr;

		deque<int> dq;

		string temp;
		for (int i = 0; i < arr.length(); i++)
			if (arr[i] == '[')
				continue;
			else if ('0' <= arr[i] && arr[i] <= '9')
				temp += arr[i];
			else if (arr[i] == ',' || arr[i] == ']')
			{
				if (!temp.empty())
				{
					dq.push_back(stoi(temp));
					temp.clear();
				}
			}

		bool print = true;
		bool left = true;
		for (int i = 0; i < function.length(); i++)
		{
			if (function[i] == 'R')
				left = !left;
			else
			{
				if (dq.empty())
				{
					print = false;
					cout << "error\n";
					break;
				}
				else
				{
					if (left)
						dq.pop_front();
					else
						dq.pop_back();
				}
			}
		}

		if (print)
		{
			if (left)
			{
				cout << "[";
				while (!dq.empty())
				{
					cout << dq.front();
					dq.pop_front();
					if (!dq.empty())
						cout << ",";
				}
				cout << "]" << endl;
			}
			else
			{
				cout << "[";
				while (!dq.empty())
				{
					cout << dq.back();
					dq.pop_back();
					if (!dq.empty())
						cout << ",";
				}
				cout << "]" << endl;
			}
		}
	}

	return 0;
}