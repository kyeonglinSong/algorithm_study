#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct RNG
{
    int seed, a, b;
    RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {}
    int next()
    {
        int result = seed;
        seed = ((seed*(long long)a) + b) % 20090711;
        return result;
    }
};

int runningMedian(int n, RNG rng)
{
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int result = 0;

    for(int i=1 ; i<=n ; i++)
    {
        if(maxHeap.size() == minHeap.size())
            maxHeap.push(rng.next());
        else
            minHeap.push(rng.next());

        if(!minHeap.empty() && !maxHeap.empty() && minHeap.top()<maxHeap.top())
        {
            int a = maxHeap.top();
            int b = minHeap.top();
            maxHeap.pop();
            minHeap.pop();
            maxHeap.push(b);
            minHeap.push(a);
        }
        result = (result + maxHeap.top()) % 20090711;
    }
    return result;
}

int main()
{
    int test;
    cin >> test;

    for(int i=0 ; i<test ; i++)
    {
        int n, a, b;
        cin >> n >>a >> b;
        runningMedian(n, RNG(a,b));
    }

}