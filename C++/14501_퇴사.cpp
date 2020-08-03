#include <iostream>
using namespace std;

int n;
int result = -1;
int take[16];
int pay[16];

void dfs(int day, int sum)
{
    if(day == n+1)
        result = max(result, sum);
    else
    {
        if(day+take[day]<=n+1)
            dfs(day+take[day], sum+pay[day]);
        dfs(day+1, sum);
    }
}

int main()
{
    cin >> n;
    for(int i=1 ; i<=n ; i++)
        cin >> take[i] >> pay[i];

    dfs(1,0);
    cout << result;
    return 0;
}