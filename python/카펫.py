def solution(brown, red):
    width = brown+red
    for i in range(brown//2, 0, -1):
        for j in range(1, brown//2):
            if i<j : break
            if i*j == width :
                if (i*2)+(j*2)-4 == brown:
                    return [i,j]