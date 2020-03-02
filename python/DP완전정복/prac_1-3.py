# ±¸±¸´ÜÀ» Àç±Í·Î
def print_table(n, i):
  if i > 9:
    return
  print(n*i)
  return print_table(n, i+1)
  
print_table(9, 1)

