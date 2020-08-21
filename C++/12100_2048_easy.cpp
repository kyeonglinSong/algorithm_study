#include <iostream>
#include <vector>
using namespace std;

int n;
int result = 0;

vector<vector<int>> down(vector<vector<int>> board)
{
     for(int i=0 ; i<n ; i++)
    {
        for(int j=n-1 ; j>=1 ; j--)
        {
            //내가 0이면
            if(board[j][i]==0)
            {
                for(int k=j-1 ; k>=0 ; k--)
                {
                    if(board[k][i]!=0)
                    {
                        board[j][i] = board[k][i];
                        board[k][i] = 0;
                        break;
                    }
                }
            }
        }
    }

    for(int i=0 ; i<n ; i++)
    {
        for(int j=n-1 ; j>=1 ; j--)
        {
            if(board[j-1][i] == board[j][i] && board[j][i]!=0)
            {
                board[j][i] *=2;
                board[j-1][i] = 0;
            }
        }
    }
    
     for(int i=0 ; i<n ; i++)
    {
        for(int j=n-1 ; j>=1 ; j--)
        {
            //내가 0이면
            if(board[j][i]==0)
            {
                for(int k=j-1 ; k>=0 ; k--)
                {
                    if(board[k][i]!=0)
                    {
                        board[j][i] = board[k][i];
                        board[k][i] = 0;
                        break;
                    }
                }
            }
        }
    }
    return board;
}
vector<vector<int>> up(vector<vector<int>> board)
{
     for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n-1 ; j++)
        {
            //내가 0이면
            if(board[j][i]==0)
            {
                for(int k=j+1 ; k<n ; k++)
                {
                    if(board[k][i]!=0)
                    {
                        board[j][i] = board[k][i];
                        board[k][i] = 0;
                        break;
                    }
                }
            }
        }
    }

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n-1 ; j++)
        {
            if(board[j+1][i] == board[j][i] && board[j][i]!=0)
            {
                board[j][i] *=2;
                board[j+1][i] = 0;
            }
        }
    }
    
     for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n-1 ; j++)
        {
            //내가 0이면
            if(board[j][i]==0)
            {
                for(int k=j+1 ; k<n ; k++)
                {
                    if(board[k][i]!=0)
                    {
                        board[j][i] = board[k][i];
                        board[k][i] = 0;
                        break;
                    }
                }
            }
        }
    }
    
    return board;
}

vector<vector<int>> right(vector<vector<int>> board)
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j=n-1 ; j>=1 ; j--)
        {
            //내가 0이면
            if(board[i][j]==0)
            {
                for(int k=j-1 ; k>=0 ; k--)
                {
                    if(board[i][k]!=0)
                    {
                        board[i][j] = board[i][k];
                        board[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }

    for(int i=0 ; i<n ; i++)
    {
        for(int j=n-1 ; j>=1 ; j--)
        {
            if(board[i][j-1] == board[i][j] && board[i][j]!=0)
            {
                board[i][j] *=2;
                board[i][j-1] = 0;
            }
        }
    }
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=n-1 ; j>=1 ; j--)
        {
            //내가 0이면
            if(board[i][j]==0)
            {
                for(int k=j-1 ; k>=0 ; k--)
                {
                    if(board[i][k]!=0)
                    {
                        board[i][j] = board[i][k];
                        board[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
    
    return board;
}

vector<vector<int>> left(vector<vector<int>> board)
{
     for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n-1 ; j++)
        {
            //내가 0이면
            if(board[i][j]==0)
            {
                for(int k=j+1 ; k<n ; k++)
                {
                    if(board[i][k]!=0)
                    {
                        board[i][j] = board[i][k];
                        board[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n-1 ; j++)
        {
            if(board[i][j+1] == board[i][j] && board[i][j]!=0)
            {
                board[i][j] *=2;
                board[i][j+1] = 0;
            }
        }
    }
    
     for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n-1 ; j++)
        {
            //내가 0이면
            if(board[i][j]==0)
            {
                for(int k=j+1 ; k<n ; k++)
                {
                    if(board[i][k]!=0)
                    {
                        board[i][j] = board[i][k];
                        board[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
    
    return board;
}

void game(int num, vector<vector<int>> board)
{
    if(num == 5)
    {
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(board[i][j]>result)
                    result = board[i][j];
            }
        }
        return;
    }
    else
    {
        game(num+1, up(board));
        game(num+1, down(board));
        game(num+1, right(board));
        game(num+1, left(board));
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);

    vector<vector<int>> board;
    cin >> n;
    int temp_num;
    for(int i=0 ; i<n ; i++)
    {
        vector<int> temp_vector;
        for(int j=0 ; j<n ; j++)
        {
            cin >> temp_num;
            temp_vector.push_back(temp_num);
        }
        board.push_back(temp_vector);
    }
    game(0, board);
    cout << result;
}