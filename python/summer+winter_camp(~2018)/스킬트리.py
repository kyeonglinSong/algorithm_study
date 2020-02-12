def solution(skill, skill_trees):
    new_skill = []
    for now in skill_trees:
        temp=""
        for i in range(len(now)):
            if now[i] in skill:
                temp += now[i]
        new_skill.append(temp)
    
    result = 0
    for now in new_skill:
        if now == skill:
            result +=1
        elif now == "":
            result += 1
        else:
            if now[0] != skill[0]:
                pass
            else:
                if now in skill:
                    result +=1 
    return result
