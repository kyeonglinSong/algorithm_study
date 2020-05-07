#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> temp;
vector<vector<string>> ban_list;
int result = 0;

void check_id(vector<string>& banned_id, vector<string> temp)
{
    bool flag = true;

    for(int i=0 ; i<banned_id.size() ; i++)
    {
        string ban = banned_id[i];
        string user = temp[i];

        if(ban.length()!=user.length())
        {
            flag = false;
            break;
        }
        for(int j=0 ; j<ban.length() ; j++)
        {
            if(ban[j]!=user[j] && ban[j]!='*')
            {
                flag = false;
                break;
            }
        }
    }

    // 마지막 중복검사
    if(flag==true)
    {
        sort(temp.begin(), temp.end());
        for(int i=0 ; i<ban_list.size() ; i++)
        {
            vector<string> nowlist = ban_list[i];
            bool flag2 = true;
            for(int j=0 ; j<ban_list[i].size() ; j++)
            {
                if (nowlist[j] != temp[j])
                {
                    flag2 = false;
                    break;
                }
            }
            if (flag2==true)
            {
                flag = false;
                break;
            }
        }
    }

    // 중복체크 리스트에 집어넣고 카운트 증가
    if(flag==true)
    {
        ban_list.push_back(temp);
        result++;
    }
}


void bf(vector<bool>& check, vector<string>& user_id, int start, int end, vector<string>& banned_id)
{
    if(end == 0)
    {
        check_id(banned_id, temp);
        /*
        for(int i=0 ; i<temp.size() ; i++)
            cout << temp[i] << " ";
        cout << "\n";
        */
        return;
    }

    for(int i=0 ; i<user_id.size() ; i++)
    {
        if(check[i] == true)
            continue;
        temp.push_back(user_id[i]);
        check[i] = true;
        bf(check, user_id, start+1, end-1, banned_id);
        check[i] = false;
        temp.pop_back();
    }
}

int solution(vector<string>& user_id, vector<string>& banned_id)
{
    vector<bool> check(user_id.size(), false);
    bf(check, user_id, 0, banned_id.size(), banned_id);

    return result;
}

int main()
{
    vector<string> user_id;
    user_id.push_back("frodo");
    user_id.push_back("fradi");
    user_id.push_back("crodo");
    user_id.push_back("abc123");
    user_id.push_back("frodoc");

    vector<string> banned_id;
    banned_id.push_back("fr*d*");
    banned_id.push_back("*rodo");
    banned_id.push_back("******");
    banned_id.push_back("******");

    cout << solution(user_id, banned_id);

    return 0;
}
