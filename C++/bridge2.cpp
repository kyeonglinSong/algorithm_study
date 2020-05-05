#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool check(int mid, vector<int> stones, int k)
{
    int count = 0;
    bool flag = false;
    for(int i=0 ; i<stones.size() ; i++)
    {
        if (stones[i] < mid)
        {
            count++;
            if(count == k)
            {
                flag = true;
                break;
            }
        }
        else
            count = 0;
    }

    return flag;
}

int main()
{
    int k=3;
    vector<int>stones;
    stones.push_back(4);
    stones.push_back(1);
    stones.push_back(1);
    stones.push_back(5);
    stones.push_back(2);
    stones.push_back(2);
    stones.push_back(2);


    int max_val = stones[0];
    int min_val = stones[0];
    int mid;
    for(int i=1 ; i<stones.size() ; i++)
    {
        max_val = max(max_val, stones[i]);
        min_val = min(min_val, stones[i]);
    }

    int result = 0;
    while (min_val <= max_val)
    {
        mid = (min_val + max_val) / 2;
        
        if(check(mid, stones, k) == true)
            max_val = mid-1;
        else
        {
            result = mid;
            min_val = mid + 1;        
        }   
    }

    cout << result;
}