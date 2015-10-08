f = open('tests_peor_caso.in', 'w')
a = 50

while (a <= 1000):
  graph = ''
  for j in range(0, a+1):
    for k in range (j+1, a+1):
      edge = '' + str(j) + ' ' + str(k) + ';' 
      graph = graph + edge 

  a += 50
  graph = graph + '\n'
  f.write(graph)
