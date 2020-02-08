def solution(clothes):
    result = dict()
    for i in clothes:
        if i[1] in result:
            result[i[1]] +=1
        else:
            result[i[1]] = 2
    mul = 1
    for i in result.values():
        mul *= i
    return mul-1

# 계산 = 각 옷 종류의 갯수+1을 다 곱함, 거기서 아무것도 안 입은 경우 1을 빼줌
