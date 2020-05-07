#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> temp;

void lotto(vector<bool> check, vector<int>& number, int start, int end)
{
    if (end == 6)
    {
        sort(temp.begin(), temp.end());
        for(int i=0 ; i<6 ; i++)
            cout << temp[i] << " ";
        cout <<"\n";
        return;
    }

    for(int i=start ; i<n ; i++)
    {
        if(check[i]==true)
            continue;
        temp.push_back(number[i]);
        check[i]=true;
        lotto(check, number, start+1, end+1);
        temp.pop_back();
        //check[i] = false;
    }
}

int main()
{
     vector<int> number = {};
    while(true)
    {
        cin >> n;
        if (n==0)
            break;
        number.clear();
        vector<bool> check(n, false);
        int temp;
        for(int i=0 ; i<n ; i++)
        {
            cin >> temp;
            number.push_back(temp);
        }

        lotto(check, number, 0, 0);
        cout << "\n";
    }

    return 0;
}