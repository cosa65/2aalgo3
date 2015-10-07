f = open('tests_peor_caso.in', 'w')
a = 10
while (a <= 100):
  graph = ''
  for j in range(0, a+1):
    for k in range (j+1, a+1):
      edge = '' + str(j) + ' ' + str(k) + ';' 
      graph = graph + edge 

  a += 10
  graph = graph + '\n'
  f.write(graph)

a += 100
a -= 10

while (a <= 1000):
  graph = ''
  for j in range(0, a+1):
    for k in range (j+1, a+1):
      edge = '' + str(j) + ' ' + str(k) + ';' 
      graph = graph + edge 

  a += 100
  graph = graph + '\n'
  f.write(graph)
