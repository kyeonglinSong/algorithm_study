def solution(numbers):
    numbers = list(map(str, numbers))
    numbers.sort(key=lambda x:x*3, reverse=True)
    return str(int(''.join(numbers)))

# 마지막 str(int()) 는 0일경우, 0000을 0 으로 바꿔주기 위함