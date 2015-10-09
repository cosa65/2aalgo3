import random

f = open('tests_peor_caso.in', 'w')
a = 50

while (a <= 1000):
  graph = ''
  for j in range(0, a+1):
    for k in range (j+1, a+1):
      weigth = random.randint(0, a)
      edge = '' + str(j) + ' ' + str(k) + ' ' + str(weigth) + ';' 
      graph = graph + edge 

  a += 50
  graph = graph + '\n'
  f.write(graph)
