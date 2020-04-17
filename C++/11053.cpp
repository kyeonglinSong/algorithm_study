#include <iostream>
using namespace std;

const int MAX = 1001;
int num; // 입력 배열의 원소 갯수
int arr[MAX]; // 입력 배열

int longest_increasing_subseq()
{
    int h[MAX] = {0}; // i로 끝나는 최장 증가 부분수열의 길이 배열
    int max = 0; // 현재 max

    for(int i=1 ; i<=num ; i++) // arr[i]에서의 최장 증가 부분수열의 길이를 구한다
        for(int j=0 ; j<i ; j++)
            if (arr[i] > arr[j] && h[i] < h[j]+1) 
                h[i] = h[j]+1;

    for(int i=1 ; i<=num ; i++) // h[i]중 최댓값을 구한다
        if(max < h[i])
            max = h[i];

    return max; // 최댓값을 리턴한다
}

int main()
{
    cin >> num;
    for (int i=1 ; i<=num ; i++)
        cin >> arr[i];

    cout << longest_increasing_subseq();

    return 0;
}