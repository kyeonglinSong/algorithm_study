def solution(bl, mw, tw):
    q = [0]*bl
    time = 0
    now=sum(q)
    while q:
        time += 1
        now-=q.pop(0)
        if tw:
            if now+tw[0] <= mw:
                new = tw.pop(0)
                q.append(new)
                now+=new
            else:
                q.append(0)
    return time

#sum()이 시간을 많이 잡아먹는다는걸 기억하자!
