def solution(dirs):
    walk = [[0,0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0,0]] #좌표평면
    move = [[-1,0], [1,0], [0,1], [0,-1]] #UDRL
    result = set()
    now = [5,5]
    count = 0

    for i in dirs:
        step = []
        if i =="U":
            step = move[0]
        elif i == "D":
            step = move[1]
        elif i == "R":
            step = move[2]
        else:
            step = move[3]
        #위치넘으면 반영 안하고 continue
        if now[0]+step[0]<0 or now[0]+step[0]>10 or now[1]+step[1]<0 or now[1]+step[1]>10:
            continue
        #안넘는경우엔 내 위치 바꿈
        else:
            temp = now
            now = [now[0]+step[0], now[1]+step[1]]
            if (now[0],now[1],temp[0],temp[1])not in result:
                result.add((now[0],now[1],temp[0],temp[1]))
                result.add((temp[0],temp[1],now[0],now[1]))
                count += 1
        
    return count

    # 양방향임을 명심하자 (이전점, 지금 점 다 포함해서 해야함!)