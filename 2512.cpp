#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int result = -1;
    int n, m;
    vector<int> req;
    
    cin >> n;
    int temp;
    int max_req = 0;
    for(int i=0 ; i<n ; i++)
    {
        cin >> temp;
        req.push_back(temp);
        max_req = max(max_req, temp);
    }

    cin >> m;

    //sort(req.begin(), req.end());

    int low = 0;
    int high = max_req;
    int mid;
    long long sum = 0;

    while(low<=high)
    {
        mid = (low+high)/2;

        for(int i=0 ; i<n ; i++)
            sum += min(mid, req[i]);

        if(sum <= m)
        {
            result = mid;
            low = mid+1;
        }
        else
            high = mid-1;
        
        sum = 0;
    }
    cout << result;
    return 0;
    
}