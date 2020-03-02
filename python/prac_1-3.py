# 구구단을 재귀로
def print_table(n, i):
  if i > 9:
    return
  print(n*i)
  return print_table(n, i+1)
  
print_table(9, 1)

