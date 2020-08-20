#include <iostream>
using namespace std;

int n;
int arr[1001];
int memo[1001] = {0};

int dp(int num)
{
    memo[1] = 1;
    int result=0;

    for(int i=2 ; i<=num ; i++)
    {
        int temp_max = 0;
        for(int j=i-1 ; j>=1 ; j--)
        {
            if(arr[j]<arr[i])
                temp_max = max(memo[j], temp_max);
        }
        memo[i] = temp_max+1;
        result = max(result, memo[i]);
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=1 ; i<=n ; i++)
        cin >> arr[i];
    
    cout << dp(n) << "\n";
    for(int i=1 ; i<=n ; i++)
        cout << memo[i] << " ";

}