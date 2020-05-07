#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(string s) 
{
    vector<pair<int,vector<int>>> tuple;
    vector<int> temp;
    int len = 0;
    
    for(int i=1 ; i<s.length()-1 ; i++)
    {
        string str = "";
        // {
        if (s[i] =='{')
        {
            temp.clear();
            len = 0;
        }
        // 숫자
        else if (s[i]>='0' && s[i]<='9')
        {
            // , 까지 여기서 처리
            str = "";
            str += s[i];
            int j = i+1;
            while(s[j]>='0' && s[j]<='9')
            {
                str+=s[j];
                i+=1;
                j+=1;
            }
            temp.push_back(stoi(str));
            len++;
        }
        else if (s[i] =='}')
            tuple.push_back(make_pair(len, temp));
    
    }
    sort(tuple.begin(), tuple.end());

    vector<int> result;
    for(int i=0 ; i<tuple.size() ; i++)
    {
        for(int j=0 ; j<tuple[i].second.size() ; j++)
        {
            int now = tuple[i].second[j];
            if (result.empty())
            {
                result.push_back(now);
            }
            else
            {
                bool flag = false;
                for(int k=0 ; k<result.size() ; k++)
                {
                    // 이미 있으면 플래그바꾸기
                    if (result[k] == now)
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag==false)
                    result.push_back(now);
            }        
        }
    }
    return result;
}
int main()
{
    string s = "{{1,2,3},{2,1},{1,2,4,3},{2}}";
    vector<int>result = solution(s);

    for(int i=0 ; i<result.size() ; i++)
        cout << result[i] << " ";

    return 0;
}