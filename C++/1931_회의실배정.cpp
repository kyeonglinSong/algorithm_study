#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> times;

bool compare(pair<int, int> a, pair<int, int> b)
{
        return a.second < b.second;
}
int solution()
{
    sort(times.begin() , times.end());
    sort(times.begin(), times.end(), compare);
    
    int index = times[0].second;
    int count = 1;
    for(int i=1 ; i<times.size() ; i++)
    {
        if(times[i].first >=index)
        {
            index = times[i].second;
            count++;
        }
    }
    return count;
}

int main()
{
    cin >> n;
    for(int i=0 ; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        times.push_back(make_pair(a,b));
    }
    cout << solution();
}
