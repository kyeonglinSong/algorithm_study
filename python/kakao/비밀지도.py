def solution(n, arr1, arr2):
    map1 = []
    map2 = []
    for i in arr1:
        map1.append(str(bin(i)[2:]).rjust(n,'0'))
    for i in arr2:
        map2.append(str(bin(i)[2:]).rjust(n,'0'))
    
    print(map2)
    result=[]
    for i in range(n):
        temp = ""
        for j in range(n):
            print(map1[i][j], map2[i][j])
            if map1[i][j] is "0" and map2[i][j] is "0":
                temp+=" "
            else:
                temp+="#"
        result.append(temp)
        
    return result