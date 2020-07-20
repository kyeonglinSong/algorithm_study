#include <iostream>
using namespace std;

const int MAX = 1001;
int vertex;
bool map[MAX][MAX];
bool visited[MAX];

void dfs(int v)
{
    int i;
    visited[v] = 1;
    for(int i=1 ; i<=vertex ; i++)
    {
        if(map[v][i]==true && !visited[i])
            dfs(i);
    }
}

int main()
{
    int n;
    cin >> vertex >> n;

    for(int i=0 ; i<MAX ; i++)
    {
        for(int j=0 ; j<MAX ; j++)
            map[i][j] = 0;
    }
    int a, b;
    for(int i=0 ; i<n ; i++)
    {
        cin >> a >> b;
        map[a][b] = map[b][a] = 1;
    }
    
    int start = 1;
    int result = 0;

    for(int i=1 ; i<=vertex ; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            result++;
        }
    }
    cout << result;
    return 0;
    
}