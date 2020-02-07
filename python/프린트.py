def solution(pri, location):
    count = 0
    maxVal = max(pri)
    while True:
        now = pri.pop(0)
        if now == maxVal:
            count+=1
            if location == 0:
                break
            else:
                location -= 1
            maxVal = max(pri)
        else:
            pri.append(now)
            if location == 0:
                location = len(pri)-1
            else:
                location -=1
    return count

# location 변수 자체를 줄일수도 있다!