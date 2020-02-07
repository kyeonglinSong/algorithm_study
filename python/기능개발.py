def solution(p, s):
    days = []
    result = []
    
    for i in range(0, len(p)):
        days.append((100-p[i])//s[i])
        if (100-p[i])%s[i] is not 0:
            days[i]+=1
    days = list(reversed(days))
    
    now = days.pop()
    count = 1
    while days:
        next = days.pop()
        if now >= next :
            count += 1
        else:
            result.append(count)
            now = next
            count = 1
            
    result.append(count)
    return result