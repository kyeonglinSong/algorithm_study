#include <iostream>
#include <vector>
using namespace std;

int k;
int lotto[13];
int check[13];

void dfs(int index, int depth)
{
    if(depth == 6)
    {
        for(int i=0 ; i<6 ; i++)
            cout << check[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=index ; i<k ; i++)
    {
        check[depth] = lotto[i];
        dfs(i+1, depth+1);
    }
}

int main()
{
    while(true)
    {
        cin >> k;
        if(k==0)
            break;

        for(int i=0 ; i<k ; i++)
            cin >> lotto[i];

        cout << "\n";
        dfs(0,0);
        cout << "\n";
    }

    return 0;
}