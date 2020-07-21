#include <iostream>
#include <queue>
using namespace std;

const int MAX = 101;

int n, m;
int map[MAX][MAX];
bool visited[MAX][MAX];

typedef struct {
    int y;
    int x;
    int length;
} direction;

int bfs(int y, int x, int length)
{
    int result = 0;
    queue<direction> q;
    direction start = {y, x, length};
    q.push(start);

    int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    while(!q.empty())
    {
        int now_y = q.front().y;
        int now_x = q.front().x;
        int now_len = q.front().length;

        if(now_y==n-1 && now_x==m-1)
        {
            result = now_len;
            break;
        }
        q.pop();
        visited[now_y][now_x] = 1;

        for(int i=0 ; i<4 ; i++)
        {
            direction temp = {dir[i][0]+now_y, dir[i][1]+now_x, now_len+1};
            if(map[temp.y][temp.x] && temp.y>=0 && temp.y<n && temp.x>=0 && temp.x<m && !visited[temp.y][temp.x])
            {
                visited[temp.y][temp.x] = 1;
                q.push(temp);
            }
        }
    }
    return result;
}

int main()
{
    cin >> n >> m;

    for(int i=0 ; i<n ; i++)
    {
        string temp;
        cin >> temp;
        for(int j=0 ; j<m ; j++)
        {
            map[i][j] = temp[j]-'0';
            visited[i][j] = 0;
        }
    }

    /*
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
           cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    */
    
    cout << bfs(0,0,1);
    return 0;
}