def solution(p):
    result = [0]*(len(p))
    for i in range(0,len(p)-1):
        for j in range(i+1, len(p)):
            result[i] +=1
            if p[i] > p[j]:
                break
    return result