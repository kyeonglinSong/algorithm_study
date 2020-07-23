#include <iostream>
#include <queue>
using namespace std;
 
const int MAX = 1001;
bool visited[MAX];
int graph[MAX][MAX];
queue<int> q;

int n, m, start;

void dfs(int vertex)
{
    visited[vertex] = 1;
    cout << vertex << " ";
    for(int i=1 ; i<=n ; i++)
    {
        if(!visited[i] && graph[vertex][i])
            dfs(i);
    }
}

void bfs(int vertex)
{
    visited[vertex] = 1;
    q.push(vertex);
    while(!q.empty())
    {
        int now = q.front();
        cout << now << " ";
        q.pop();
        for(int i=1 ; i<=n ; i++)
        {
            if(!visited[i] && graph[now][i])
            {
                q.push(i);
                visited[i] = 1;
            }

        }
    }
}

int main()
{
    cin >> n >> m >> start;
    for(int i=0 ; i<MAX ; i++)
    {
        for(int j=0 ; j<MAX ; j++)
            graph[i][j] = 0;
        visited[i] = 0;
    }
    for(int i=0 ; i<m ; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1][node2] = graph[node2][node1] = 1;
    }

    dfs(start);
    cout << "\n";
    memset(visited, 0, sizeof(visited));
    bfs(start);

    return 0;
}