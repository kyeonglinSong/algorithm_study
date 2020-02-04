#200203(월) 프로그래머스-k번째수

# .sort(), sorted()의 차이를 잘 알자

def solution(array, commands):
    result = []
    for command in commands:
        temp = array[command[0]-1:command[1]]
        temp = sorted(temp)
        result.append(temp[command[2]-1])
    return result
