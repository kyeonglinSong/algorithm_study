// 2309번 일곱 난쟁이
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[9];
int i,j;

void findSeven(int sum)
{
    sort(arr, arr+9);
    for(i=0 ; i<9 ; i++)
        for(j=0 ; j<9 ; j++)
        {
            if(i!=j && sum-arr[i]-arr[j]==100)
                return;
        }
}

int main()
{
    int sum=0;
    for(int a=0 ; a<9 ; a++)
    {
        cin >> arr[a];
        sum += arr[a];
    }
    findSeven(sum);
    for(int a=0 ; a<9 ; a++)
        if(a!=i && a!=j)
            cout << arr[a] << endl;
}
