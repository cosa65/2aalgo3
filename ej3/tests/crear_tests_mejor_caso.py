import random

f = open('tests_caso_mejor.in', 'w')
a = 50

while (a <= 1000): 
  tree = ''
  for j in range(0, a):
    weigth = random.randint(0, a)
    tree = tree + str(j) + ' ' + str(j+1) + ' ' + str(weigth) + ';' + ' '  

  tree = tree + '\n'
  f.write(tree)
  a += 50
