// 삼각형 합과 경로에 있는 수 출력

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 501; // MAX : 최대 입력 길이 + 1
int num; // num : number, 입력받을 삼각형의 높이이자 밑변의 원소 수
int triangle[MAX][MAX]; // triangle : 입력받을 삼각형

// 삼각형의 최대 합 경로와 최대 합을 구하고 출력하는 함수
void number_triangle()
{
    int best[MAX][MAX] = {0}; // best : 각 원소까지의 최대 합을 저장한 배열
    // direction : 해당 원소까지의 최대경로상의 바로 윗 level 값의 방향.
    // 초기값 -1, 왼쪽 0, 오른쪽 1
    int direction[MAX][MAX] = {-1}; 

    // 초기조건, 삼각형의 맨 꼭대기값의 최대합은 값 자체이다.
    best[0][0] = triangle[0][0]; 

    // 삼각형의 각 원소에서의 최대 합과 그 이전 level 원소의 방향을 저장한다.
    for(int i=1 ; i<num ; i++)
        for(int j=0 ; j<=i ; j++)
        {
            best[i][j] = triangle[i][j] + max(best[i-1][j-1], best[i-1][j]);
            // 왼쪽 윗 값에서 내려왔다면, direction을 왼쪽으로 설정
            if (best[i-1][j-1] > best[i-1][j]) 
                direction[i][j] = 0; 
            // 오른쪽 윗 값에서 내려왔다면, direction을 오른쪽으로 설정
            else
                direction[i][j] = 1; 
        }

    int result = 0; // result : 최대 합.
    int index; // index : 최대 합의 열(column)에서의 위치 인덱스

    // 맨 아래 level에서 삼각형의 최대 합과 그 열 인덱스를 구한다.
    for(int j=0 ; j<num ; j++)
        if(result < best[num-1][j])
        {
            result = best[num-1][j];
            index = j;
        }

    // route : max sum route. 최대 합의 경로 원소를 저장한 배열
    int route[MAX] = {0};

    // 가장 밑 level에서부터 direction배열을 통해 경로를 역추적하며 최대 합 경로를 저장한다.
    for(int i=num-1 ; i>=0 ; i--)
    {
        route[i] = triangle[i][index];
        // 이전 경로 방향이 왼쪽이라면 index를 왼쪽으로 이동시킨다.
        // 열 인덱스에서 왼쪽 : n-1, 오른쪽 : n 그대로임을 이용.
        if (direction[i][index] == 0) 
            index = index-1;
    }

    // 삼각형의 최대 합과 그때의 경로를 출력한다.    
    cout << "최대 합 : " << result << "\n";
    cout << "최대 합일때의 경로 : [ ";
    for(int i=0 ; i<num ; i++)
        cout << route[i] << " ";
    cout << "]";
    
}

// 메인 함수
int main()
{
    // 삼각형의 높이와 삼각형을 구성하는 원소들을 입력받는다.
    // 높이와 원소 배열은 모두 전역변수로 선언하였다. 
    cin >> num;
    for (int i=0 ; i<num ; i++)
        for(int j=0 ; j<=i ; j++)
            cin >> triangle[i][j];
    
    // 삼각형의 최대 합 경로와 최대 합을 구하고, 출력한다.
    // 출력되는 경로는 삼각형 꼭대기에서부터 아래쪽을 향하는 경로이다.
    number_triangle();

    return 0;
}