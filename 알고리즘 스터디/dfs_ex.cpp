#include <iostream>
using namespace std;

const int MAX = 30;

int n;
int map[MAX][MAX];
bool visited[MAX];

void DFS(int v)
{
    int i;
    visited[v] = 1;
    
    for(i=1 ; i<=n ; i++)
    {
        if(map[v][i] ==1 && !visited[i])
        {
            cout << i << "\n";
            DFS(i);
        }
    }
}

int main()
{
    int start;
    cin >> n >> start;
    int a, b;

    for(int i=0 ; i<MAX ; i++)
    {
        for(int j=0 ; j<MAX ; j++)
        {
            map[i][j] = 0;
        }
        visited[i] = 0;
    }

    while(true)
    {
        cin >> a >> b;
        if(a==-1 && b==-1)
            break;
        map[a][b] = map[b][a] = 1;
    }

    cout << "\n" << start<<"\n";
    DFS(start);
    cout << "\n";
}