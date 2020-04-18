// 최장 증가 부분수열(이하 lis)의 길이와 수열을 모두 출력하는 코드.

#include <iostream>
using namespace std;

const int MAX = 1001; // MAX = 최대 입력 길이 + 1
int num; // 입력 배열의 원소 갯수
int arr[MAX]; // 입력 배열

// lis와 lis수열을 구하고, 결과들을 출력하는 함수
void longest_increasing_subseq()
{
    int h[MAX] = {0}; // arr[i]로 끝나는 lis의 길이 배열 
    int past[MAX] = {0}; // arr[i]의 바로 전 값의 인덱스 배열

    // arr[i]에서의 lis의 길이를 h배열에 저장한다.
    for(int i=1 ; i<=num ; i++) 
        for(int j=0 ; j<i ; j++)
            if (arr[i] > arr[j] && h[i] < h[j]+1) 
            {
                // h[i]에 이전 lis의 길이 + 1(자신)을 저장한다.
                h[i] = h[j]+1;
                // past[i]에 이전 lis의 제일 마지막 인덱스를 저장한다.
                past[i] = j;
            }

    int result = 0; // 반환할 값. lis의 길이
    int index; // result의 인덱스
    
    // h[i]중 최댓값과 그 인덱스를 구한다.
    for(int i=1 ; i<=num ; i++) 
        if(result < h[i])
        {
            result = h[i];
            index = i; 
        }
    
    int lis[MAX]; // lis 수열을 저잘할 배열
    int temp = result; // lis 값들의 저장을 위한 임시 인덱스

    while(index != 0)
    {
        // arr[index]에 해당하는 값을 lis배열에 저장한다.
        lis[--temp] = arr[index]; 
        // 인덱스를 이전 값의 인덱스로 변경한다.
        index = past[index];
    }

    // lis의 길이, 수열 출력 부분
    cout << "최장 증가 부분 수열의 길이 : " << result << "\n";
    cout << "최장 증가 부분 수열 : [ ";
    for(int i=0 ; i<result ; i++)
        cout << lis[i] << " ";
    cout << "]";

}

// 메인 함수
int main()
{
    // 전체수열의 길이와 수열을 입력받는다.
    // 입력 크기와 배열은 모두 전역변수로 선언했다.
    cin >> num;
    for (int i=1 ; i<=num ; i++)
        cin >> arr[i];

    // lis와 그 길이를 구하고 출력한다.
    longest_increasing_subseq();

    return 0;
}