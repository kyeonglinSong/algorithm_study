#include <iostream>
#include <queue>
using namespace std;

int n, apple, l;
queue<pair<int, char>> direction;
deque<pair<int,int>> body;
int map[101][101];

typedef struct {
    int length;
    int torward_y;
    int torward_x;
} snake_info;

int dummy()
{
    int time=0;
    snake_info snake = {1,0,1};
    int change = direction.front().first;
    char lr = direction.front().second;
    direction.pop();
    int now_y = 1, now_x = 1;
    while(true)
    {
        if(time==change)
        {
            cout << "here ";
            if(lr=='D')
            {
                //(오른쪽으로 향하고 있었으면)
                if(snake.torward_y==0 && snake.torward_x==1)
                {
                    snake.torward_y = 1;
                    snake.torward_x = 0;
                }
                //(내려오고 있었으면)
                else if(snake.torward_y==1 && snake.torward_x==0)
                {
                    snake.torward_y = 0;
                    snake.torward_x = -1;
                }
                //(왼쪽으로 향하고 있었으면)
                else if(snake.torward_y==0 && snake.torward_x==-1)
                {
                    snake.torward_y = -1;
                    snake.torward_x = 0;
                }
                // 위로 올라오고 있었으면
                else if(snake.torward_y==-1 && snake.torward_x==0)
                {
                    snake.torward_y = 0;
                    snake.torward_x = 1;
                }

            }
            else if (lr=='L')
            {
                //(오른쪽으로 향하고 있었으면)
                if(snake.torward_y==0 && snake.torward_x==1)
                {
                    snake.torward_y = -1;
                    snake.torward_x = 0;
                }
                //(내려오고 있었으면)
                else if(snake.torward_y==1 && snake.torward_x==0)
                {
                    snake.torward_y = 0;
                    snake.torward_x = 1;
                }
                //(왼쪽으로 향하고 있었으면)
                else if(snake.torward_y==0 && snake.torward_x==-1)
                {
                    snake.torward_y = 1;
                    snake.torward_x = 0;
                }
                // 위로 올라오고 있었으면
                else if(snake.torward_y==-1 && snake.torward_x==0)
                {
                    snake.torward_y = 0;
                    snake.torward_x = -1;
                }
            }
            if(!direction.empty())
            {
                change = direction.front().first;
                lr = direction.front().second;
                direction.pop();
            }
            cout << "바뀐방향 : " << snake.torward_y << ", " <<snake.torward_x << "\n";
        }

        int next_y = now_y + snake.torward_y;
        int next_x = now_x + snake.torward_x;
        cout << "다음 y,x : " << next_y << ", " << next_x << "\n"; 

        // 종료조건 : 벽에 닿음 
        if(next_y<1 || next_y>n || next_x<1 || next_x>n)
        {            
            cout << "벽에닿음\n";
            time++;
            break;
        }
        if(map[next_y][next_x]== 2)
        {
            cout << "몸에부딪힘\n";
            time++;
            break;
        }
        // 다음칸이 빈칸
        if(map[next_y][next_x] == 0)
        {
            now_y = next_y;
            now_x = next_x;
            //머리움직임
            body.push_front(make_pair(now_y, now_x));
            map[now_y][now_x] = 2;
            // 꼬리줄임
            map[body.back().first][body.back().second] = 0;
            body.pop_back();
        }    
        // 다음칸이 사과
        else if (map[next_y][next_x] == 1)
        {
            map[next_y][next_x] = 2;
            now_y = next_y;
            now_x = next_x;
            body.push_front(make_pair(now_y, now_x));
        }     
        time++;
    }

    return time;
}

int main()
{
    cin >> n >> apple;
    int y, x;
    memset(map, 0, sizeof(map));
    for(int i=0 ; i<apple ; i++)
    {
        cin >> y >> x;
        map[y][x] = 1;
    }
    cin >> l;
    int step;
    char dir;
    for(int i=0 ; i<l ; i++)
    {
        cin >> step >> dir;
        direction.push(make_pair(step, dir));
    }
    
    body.push_back(make_pair(1,1));
    map[1][1] = 2;
    cout << dummy() << "\n";
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n ; j++)
        {
            cout << map[i][j];
        }
        cout << "\n";
    }
}
