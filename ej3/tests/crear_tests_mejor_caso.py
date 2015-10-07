import random

f = open('tests_caso_mejor.in', 'w')
a = 10
while (a <= 100): 
  tree = ''
  for j in range(0, a):
    weigth = random.randint(0, a)
    tree = tree + str(j) + ' ' + str(j+1) + ' ' + str(weigth) + ';' + ' '  

  tree = tree + '\n'
  f.write(tree)
  a += 10

a -= 10
a += 100

while (a <= 1000): 
  tree = ''
  for j in range(0, a):
    weigth = random.randint(0, a)
    tree = tree + str(j) + ' ' + str(j+1) + ' ' + str(weigth) + ';' + ' '  

  tree = tree + '\n'
  f.write(tree)
  a += 100
