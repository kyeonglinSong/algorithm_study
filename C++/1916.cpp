#include <iostream>
#include <math.h>
using namespace std;
    
const int MAX_CITY = 1001;
const int INF = 1000000000;

int graph[MAX_CITY][MAX_CITY];
int city_num;
int bus_num;

int dijkstra(int start, int end)
{
    int touch[MAX_CITY];
    int length[MAX_CITY];
    int vnear;

    // 초기화. start 도시를 제외하고 초기화시킨다. start 도시는 이미 선택되었다고 가정.
    for(int i=1 ; i<=city_num ; i++)
    {
        if(start==i)
            continue;
        touch[i] = start;
        length[i] = graph[start][i];
    }

    // 남은 노드들 탐색. city_num - 1 번 반복한다.
    for(int i=1 ; i<=city_num-1 ; i++)
    {
        int min_num = INF;
        for(int j=1 ; j<=city_num ; j++)
        {
            if(j==start)
                continue;
            if(0<= length[j] && length[j]<min_num)
            {
                min_num = length[j];
                vnear = j;
            }
        }

        for(int j=1 ; j<=city_num ; j++)
        {
            if(j==start)
                continue;
            if(length[vnear] + graph[vnear][j] < length[j])
            {
                length[j] = length[vnear] + graph[vnear][j];
                touch[j] = vnear;
            }
            
        }
        length[vnear] = -1;
    }   

    int first = end;
    int second = touch[end];
    int result= 0;

    while(first != start)
    {
        cout << graph[second][first] << " ";
        result += graph[second][first];
        first = second;
        second = touch[second];
    }
    cout << "\n";
    return result;
}

int main()
{
    for(int i=0 ; i<MAX_CITY ; i++)
        fill_n(graph[i], MAX_CITY, INF);

    cin >> city_num;
    cin >> bus_num;
    int start, end, weight;
    for(int i=0 ; i<bus_num ; i++)
    {
        cin >> start >> end >> weight;
        if(graph[start][end] == INF)
            graph[start][end] = weight;
        else
            graph[start][end] =min(graph[start][end], weight);
    }
    cin >> start >> end;

    // 답 출력
    cout << dijkstra(start, end);
}