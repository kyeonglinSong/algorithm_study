#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX = 26;

char map[MAX][MAX] = {0};
bool visited[MAX][MAX] = {0};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, house_count = 0;

void dfs(int i, int j)
{
    visited[i][j] = 1;
    for(int k=0 ; k<4 ; k++)
    {
        int x = i+dx[k];
        int y = j+dy[k];
        
        if(0 <= x && x<n && 0<=y && y<n)
        {
            if(map[x][y] == '1' && !visited[x][y])
            {
                house_count ++;
                dfs(x, y);
            }
        }
    }
}


int main()
{
    cin >> n;

    int danzi = 0;
    vector<int> house;

    for(int i=0 ; i<n ; i++)
        cin >> map[i];

    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<n ; j++)
        {
            if(map[i][j] == '1' && !visited[i][j])
            {
                danzi++;
                house_count = 1;
                dfs(i, j);
                house.push_back(house_count);
            }
        }
    sort(house.begin(), house.end());

    cout << danzi << '\n';

    for(int i=0 ; i<house.size() ; i++)
        cout << house[i] << '\n';
    
    return 0;
}
