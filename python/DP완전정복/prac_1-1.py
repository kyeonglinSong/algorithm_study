def fact_1(n):
  if n <=0:
    return 0
  if n == 1:
    return 1
  return n * fact_1(n-1)

def fact_2(n):
  if n<=0:
    return 0
  result = 1
  for i in range(1,n+1):
    result *= i
  return result
