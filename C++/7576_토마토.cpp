#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1000;

int n, m;
int box[MAX][MAX];
bool check[MAX][MAX];
int no = 0;

int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

bool allRipe()
{
    int tomato = n*m-no;
    int count = 0;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if(box[i][j]==1)
                count++;
        }
    }
    return tomato==count;
}

int bfs(int y, int x)
{
    queue<pair<int, int>> q;
    int day = 0;
    q.push(make_pair(y,x));

    while(!q.empty())
    {
        int now_y = q.front().first;
        int now_x = q.front().second;
        
        for(int i=0 ; i<4 ; i++)
        {
            int temp_y = now_y + dir[i][0];
            int temp_x = now_x + dir[i][1];
            if(temp_y>=0 && temp_y<n && temp_x>=0 && temp_x<m && box[temp_y][temp_x]==0 && !check[temp_y][temp_x])
            {
                box[temp_y][temp_x] = 1;
                q.push(make_pair(temp_y, temp_x));
            }
        }
        q.pop();
        day++;
    }
    return day;
}

int main()
{
    cin >> m >> n;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            int tomato;
            cin >> tomato;
            box[i][j] = tomato;
            if(tomato==-1)
                no++;
            check[i][j] = 0;
        }
    }

    int result = MAX;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if(box[i][j] == 1)
            {
                result =  min(result, bfs(i,j));
            }
        }
    }


    cout << "\n\n";

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            cout << box[i][j] << " ";
        }
        cout <<"\n";
    }

    cout << "\n\n";

    if(!allRipe())
        cout << -1;
    else
        cout << result;

    return 0;
}