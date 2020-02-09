def solution(genres, plays):
    genres_cnt = {}
    result = []
    for i in range(len(genres)):
        result.append([i, genres[i], plays[i]])
        if genres[i] in genres_cnt:
            genres_cnt[genres[i]] += plays[i]
        else:
            genres_cnt[genres[i]] = plays[i]

    genres_rank = sorted(list(genres_cnt.keys()), key=lambda x: genres_cnt[x])
    result.sort(key=lambda x: (genres_rank.index(x[1]), x[2], -x[0]), reverse=True)
    
    answer = []
    count = 0
    now = ""
    for i in result:
        if i[1] == now:
            count += 1
        else:
            count = 1
            now = i[1]
        if count <3:
            answer.append(i[0])
    return answer