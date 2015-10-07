f = open('tests_peor_caso.in', 'w')
a = 10
while (a <= 100):
  floors = str(a) + '\n'
  f.write(floors)
  connections = ''
  for j in range(0, a+1):
    for k in range (j+1, a+1):
      hare = '' + str(j) + ' ' + str(k) + ';' 
      connections = connections + hare

  a += 10
  connections = connections + '\n'
  f.write(connections)

a += 100
a -= 10

while (a <= 1000):
  floors = str(a) + '\n'
  f.write(floors)
  connections = ''
  for j in range(0, a+1):
    for k in range (j+1, a+1):
      hare = '' + str(j) + ' ' + str(k) + ';' 
      connections = connections + hare

  a += 100
  connections = connections + '\n'
  f.write(connections)
