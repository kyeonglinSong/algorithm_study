def solution(arr):
    arr = arr.replace("()", "a")
    stack = []
    result = 0
    
    for k in arr:
        if k == '(':
            stack.append('(')
            result += 1
        elif k == ')':
            stack.pop()
        else:
            result += len(stack)
    return result

    # ")" 일때 스택에서 뽑고, "("일때는 스택에 저장 + 카운트 올려줌