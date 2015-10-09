f = open('tests_peor_caso.in', 'w')
a = 50

#i = 0
while (a <= 1000): # and i < 3):
  floors = str(a) + '\n'
  f.write(floors)
  connections = ''
  for j in range(0, a+1):
    for k in range (j+1, a+1):
      hare = '' + str(j) + ' ' + str(k) + ';' 
      connections = connections + hare

  print a
  connections = connections + '\n'
  f.write(connections)
  #i += 1
  #if i == 3:
  a += 50
    #i = 0
