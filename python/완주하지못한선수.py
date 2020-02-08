def solution(participant, completion):
    result = dict()
    for i in participant:
        if i in result.keys():
            result[i] +=1
        else:
            result[i] = 1
    for i in completion:
        if result[i] == 1:
            del result[i]
        else:
            result[i] -= 1
            
    return list(result.keys())[0]


    