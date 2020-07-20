
/*
매일프로그래밍 코딩테스트 #35

중복된 원소가 없는 정렬된 배열이 있습니다. 
이 배열에서 원소의 값이 원소의 인덱스 값과 같다면 프린트 하시오. 
시간복잡도 O(log n).
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> arr = {-40, -30, -20, 3};

int main()
{
    int start = 0;
    int end = arr.size();
    int mid;

    while(start<=end)
    {
        mid = (start+end)/2;

        if(arr[mid] == mid)
        {
            cout << mid;
            break;
        }  
        else if(arr[mid]>mid) // 값이 인덱스보다 클 경우
        {
            end = mid;
        }
        else if (arr[mid]<mid)
        {
            start = mid+1;
        }
    }

    return 0;
}