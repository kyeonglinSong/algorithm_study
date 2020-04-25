#include <iostream>
using namespace std;

const int MAX = 101;
int n;
int arr[MAX][11] = {0};

int dp() {
    for(int i=1 ; i<10 ; i++)
        arr[1][i] = 1;

    for(int i=2 ; i<=n ; i++) {
        arr[i][0] = arr[i-1][1];
        for(int j=1 ; j<10 ; j++) 
                arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1])%1000000000;
    }
/*
    for(int i=0 ; i<=n ; i++)   {
        for(int j=0 ; j<11 ; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
*/
    long result = 0;
    for(int i=0 ; i<10 ; i++)
        result += arr[n][i];

    return result%1000000000;
}

int main() {
    cin >> n;
    cout << dp();

    return 0;
}