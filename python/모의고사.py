def solution(answers):
    student = [[1,2,3,4,5], [2,1,2,3,2,4,2,5], [3,3,1,1,2,2,4,4,5,5]]
    count = [0,0,0]
    
    for answer_num, answer in enumerate(answers):
        for stu_num, stu in enumerate(student):
            if answer == stu[answer_num % len(stu)]:
                count[stu_num] += 1
    
    max_num = max(count)
    result = []
    for i in range(0, len(count)):
        if count[i] == max_num:
            result.append(i+1)
            
    return result

# 마지막 result를 return [i+1 for i, score in enumerate(count) if score==max(count)] 로 압축할 수 있다