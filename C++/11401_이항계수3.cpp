#include <iostream>
using namespace std;
// M : 나눠야 하는 큰 수
const long long  M = 1000000007LL; 

// (k!(n-k)!)^(M-2)를 구하는 함수
long long mul(long long x, long long y) 
{
    long long result = 1;
    while (y > 0) 
    {
        // y가 홀수면
        if (y%2 != 0) {
            result *= x;
            result %= M;
        }
        x *= x;
        x %= M;
        y/=2;
    }
    // 계산한 값 리턴
    return result;
}

// 이항 계수(binomial coefficient)를 구하는 함수
long long bc(long long n, long long k)
{
    long long result = 1;
    long long t1 = 1; // t1 = n!
    long long t2 = 1; // t2 = n!(n-k)!
    // n! 구하기
    for (long long i=1; i<=n; i++) {
        t1 *= i;
        t1 %= M;
    }
    // k! 구하기
    for (long long i=1; i<=k; i++) {
        t2 *= i;
        t2 %= M;
    }
    // k!에 (n-k)! 곱하기 -> k!(n-k)! 만들기
    for (long long i=1; i<=n-k; i++) {
        t2 *= i;
        t2 %= M;
    }
    // (k!(n-k)!)^(M-2) 구하기
    long long t3 = mul(t2, M-2);
    // (k!(n-k)!)^(M-2) mod M 계산
    t3 %= M;
    // n! * (k!(n-k)!)^(M-2) mod M 계산
    result = t1*t3;

    // 계산값을 1,000,000,007으로 나눠서 리턴
    return result%M;
}

// 메인 함수
int main() 
{
    long long n, k;
    cin >> n >> k;

    // 이항계수를 구해서 결과 출력
    cout << bc(n, k);

    return 0;
}