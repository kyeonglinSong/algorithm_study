def cumulate(n):
  if n == 1:
    return 1
  return cumulate(n-1)+n

def result(arr):
  for i in range(0,len(arr)):
    arr[i] = cumulate(i+1)
  return arr

