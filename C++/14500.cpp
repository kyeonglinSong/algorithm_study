#include <iostream>
#include <vector>
using namespace std;

int n,m;
int map[500][500];
vector<vector<pair<int,int>>> block;

typedef struct {
    int x;
    int y;
} location;

void make_block()
{
    //block1
    block.push_back({{0,0}, {1,0}, {2,0}, {3,0}});
    block.push_back({{0,0}, {0,1}, {0,2}, {0,3}});
    //block2
    block.push_back({{0,0}, {0,1}, {1,0}, {1,1}});
    //block3
    block.push_back({{-1,0}, {0,0},{1,0},{0,1}});
    block.push_back({{-1,0}, {0,0},{1,0},{0,-1}});
    block.push_back({{-1,0}, {0,0},{0,-1},{0,1}});
    block.push_back({{1,0}, {0,0},{0,-1},{0,1}});
    //block4
    block.push_back({{0,0}, {0,1},{1,0},{1,-1}});    
    block.push_back({{0,0}, {1,0},{0,-1},{1,1}});
    block.push_back({{0,0}, {0,1},{-1,0},{1,1}}); 
    block.push_back({{0,0}, {1,0},{0,1},{-1,1}}); 

    //block
    block.push_back({{0,0}, {-1,0},{-2,0},{0,1}}); 
    block.push_back({{0,0}, {-1,0},{-2,0},{0,-1}}); 

    block.push_back({{0,0}, {0,1},{0,2},{1,0}}); 
    block.push_back({{0,0}, {0,1},{0,2},{-1,0}}); 

    block.push_back({{0,0}, {0,-1},{0,-2},{1,0}}); 
    block.push_back({{0,0}, {0,-1},{0,-2},{-1,0}}); 

    block.push_back({{0,0}, {1,0},{2,0},{0,1}}); 
    block.push_back({{0,0}, {1,0},{2,0},{0,-1}}); 
}

int calc()
{
    int result = 0;
    location one, two, three, four;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            for(int k=0 ; k<block.size() ; k++)
            {
                vector<pair<int,int>> now = block[k];
                one = {j+now[0].second , i+now[0].first};
                two = {j+now[1].second , i+now[1].first};
                three = {j+now[2].second , i+now[2].first};
                four = {j+now[3].second , i+now[3].first};

                if( one.x>=0 && one.x<m && one.y>=0 && one.y<n
                    && two.x>=0 && two.x<m && two.y>=0 && two.y<n
                    && three.x>=0 && three.x<m && three.y>=0 && three.y<n
                    && four.x>=0 && four.x<m && four.y>=0 && four.y<n)
                    {
                        int temp = map[one.y][one.x] + map[two.y][two.x] + map[three.y][three.x] + map[four.y][four.x];
                        result = max(result, temp);
                    }
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
        for(int j=0 ; j<m ; j++)
            cin >> map[i][j];
    }
    make_block();
    cout << calc();
}