import random

def bfs(graph, start):
  visited, stack = set(), [start] 
  while stack:
    vertex = stack.pop()
    if vertex not in visited:
      visited.add(vertex)
      stack.extend(graph[vertex] - visited)

  return visited 

f = open('tests_caso_promedio.in', 'w')
a = 50
graph = {}
k = 0
while (a <= 1000): 
  for i in range(0, a+1):
    graph[i] = set()
  connec = ''
  for j in range(0, (a*(a-10)/2)):
    vertex1 = random.randint(0, a)
    vertex2 = random.randint(0, a)
    while (vertex1 == vertex2):
      vertex2 = random.randint(0, a)

    if vertex1 > vertex2:
      graph[vertex2].update([vertex1])
    else:
      graph[vertex1].update([vertex2])


  arbol = bfs(graph, 0) 
  #print arbol
  es_arbol = True
  for i in range(0, a+1):
    if i not in arbol:
      es_arbol = False

  if (es_arbol):
    print a
    for vertex in graph:
      for edge in graph[vertex]:
        weigth= random.randint(0, a)
        connec = connec + str(vertex) + ' ' + str(edge) + ' ' + str(weigth) + ';' + ' ' 

    connec = connec + '\n'
    f.write(connec)
    k += 1
    if k == 3:
      a += 50 
      k = 0
