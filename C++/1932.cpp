#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 500;
int num;
int arr[MAX][MAX];

int number_triangle()
{
    int best[MAX][MAX] = {0};
    int result = 0;

    best[0][0] = arr[0][0]; // 초기조건, 삼각형의 맨 꼭대기값은 그대로.
    for(int i=1 ; i<=num ; i++)
        for(int j=0 ; j<=i ; j++)
            best[i][j] = arr[i][j] + max(best[i-1][j-1], best[i-1][j]);
    
    for(int j=0 ; j<num ; j++)
        if(result < best[num][j])
            result = best[num][j];
    
    return result;
}

int main()
{
    cin >> num;
    for (int i=0 ; i<num ; i++)
        for(int j=0 ; j<=i ; j++)
            cin >> arr[i][j];
    
    cout << number_triangle();

    return 0;
}