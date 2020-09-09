#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> tops;

vector<int> signal()
{
    vector<int> result;
    result.push_back(0);
    for(int i=1 ; i<tops.size() ; i++)
    {
        // 앞에애보다 내가 크면
        if(tops[i-1] <tops[i])
        {
            for(int j=result[i-1] ; j>=0 ; j--)
            {
                if(tops[j] > tops[i])
                {
                    result.push_back(j+1);
                    break;
                }
                if(j==0)
                    result.push_back(0);
            }

        }
        // 앞에애가 더 크면
        else
        {
            result.push_back(i);
        }
        
    }

    return result;
}

int main()
{
    cin >> n;
    int temp;
    for(int i=0 ; i<n ; i++)
    {    
        int temp;
        cin >> temp;
        tops.push_back(temp);
    }
    vector<int> result = signal();
    for(int i=0 ; i<result.size() ; i++)
        cout << result[i] << " ";
    
    return 0;
}