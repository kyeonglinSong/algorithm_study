// 9095 1,2,3 더하기

#include <iostream>
using namespace std;

int n;
int cache[12];

int dp()
{
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;

    for(int i=4 ; i<=n ; i++)
        cache[i] = cache[i-1] + cache[i-2] + cache[i-3];
    return cache[n];
}

int main()
{
    int test;
    cin >> test;
    for(int i=0 ; i<test ; i++)
    {
        cin >> n;
        cout << dp() << endl;
    }
    return 0;
}