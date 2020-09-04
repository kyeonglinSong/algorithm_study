#include <string>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

vector<int> solution(vector<string> gems) 
{
    unordered_map<string, int> m;
    // 종류개수구하기
    for(int i=0 ; i<gems.size() ; i++)
    {
        if(m.find(gems[i])==m.end())
            m.insert(make_pair(gems[i], 1));
        else
            m[gems[i]]++;
    }
    int number = m.size();
    if(number==1)
        return {1,1};
    m.clear();

    vector<int> answer = {0,0};
    int gap = 102030102;
    int start=0;
    int end=0;
    
    while(true)
    {   
        // 종류 개수 맞을때
        if(m.size() == number)
        {
            m[gems[start]]--;
            if(m[gems[start]] == 0)
                m.erase(gems[start]);
            start++;
        }
        // 마지막 포인터가 갔을 경우
        else if (end == gems.size())
        {
            break;
        }
        // 뒤를 늘리기
        else
        {
            m[gems[end]]++;
            end++;
        }

        //체크해보기
        if(m.size() == number)
        {
            if(abs(end-start) < gap)
            {
                gap = abs(end-start);
                answer[0] = start+1;
                answer[1] = end;
            }
        }
        
    }
    return answer;
}
int main()
{
    vector<string> gems = {"1","1","1","2","1"};
    vector<int> result = solution(gems);

    cout << result[0] << ", " << result[1];
}