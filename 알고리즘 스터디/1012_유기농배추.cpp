#include <iostream>
using namespace std;

const int MAX = 50; 
int n, m, total;
int map[50][50];
bool visited[50][50];
int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void dfs(int y, int x)
{
    map[y][x] = 0;
    visited[y][x] = 1;

    for(int i=0 ; i<4 ; i++)
    {
        int temp_y = y + dir[i][0];
        int temp_x = x + dir[i][1];
        if(temp_y>=0 && temp_y<n && temp_x>=0 && temp_x<m && !visited[temp_y][temp_x] && map[temp_y][temp_x])
            dfs(temp_y, temp_x);
    }
}

int main()
{
    int test;
    cin >> test;

    for(int i=0 ; i<test ; i++)
    {
        cin >> n >> m >> total;
        int x, y;
        int count = 0;
        for(int j=0 ; j<n ; j++)
        {
            for(int k=0 ; k<m ; k++)
            {
                map[j][k] = 0;
                visited[j][k] = 0;
            }
        }
        for(int j=0 ; j<total ; j++)
        {
            cin >> y >> x;
            map[y][x] = 1;
        }
        
        // 구역 수 구하기
        for(y=0 ; y<n ; y++)
        {
            for(x=0 ; x<m ; x++)
            {
                if(map[y][x]==1)
                {
                    count++;
                    dfs(y, x);
                }
            }
        }
        cout << count << "\n";
    }
    return 0;
}