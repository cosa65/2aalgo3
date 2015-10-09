import numpy as np
import matplotlib.pyplot as plt
from math import log

# y[0..1] = mejoresCasos e=3
# y[2..4] = CasosPromedios e=3
# y[4..5] = CasoPeor e=3

#x = [3, 3, 3, 3, 3, 3]
#numeros del eje x
x= [50,100,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000]
#y = [0.000002, 0.000007, 0.000028, 0.000029, 0.000029, 0.000049]

#valores segunda funcion
f = open('tiempos_caso_promedio.txt', 'r')
yrandom1 = []
yrandom2 = []
yrandom3 = []
for i in range(0,20):
    yrandom1.append(float(f.readline()[:-1]))
    yrandom2.append(float(f.readline()[:-1]))
    yrandom3.append(float(f.readline()[:-1]))

#yrandom1 = [0.000139, 0.000139,0.000208,0.000284,0.000354,0.000425,0.000495,0.000614,0.000630,0.000729]
#yrandom2 = [0.000139, 0.000139,0.000208,0.000284,0.000354,0.000425,0.000495,0.000614,0.000630,0.000729]
#yrandom2 = [0.000139, 0.000139,0.000208,0.000284,0.000354,0.000425,0.000495,0.000614,0.000630,0.000729]

ypeor = []
f = open('tiempos_peor_caso.txt', 'r')
for line in f:
  ypeor.append(float(line[:-1]))


#ypeor = [0.000161,0.000161,0.000238,0.000323,0.000388,0.000491,0.000584,0.000693,0.000776,0.000840]

#'ro' te dice que lo plotee con los numeritos que escribiste, como puntitos en el grafico
#print len(ymejor_grande)
#print len(yrandom1_grande)
#print len(yrandom2_grande)
#print len(yrandom3_grande)
#print len(ypeor_grande)
#print len(x_grande)
#mejor_caso = plt.plot(x,ymejor,'ro', color='green', marker='o', label='Mejor Caso')
plt.plot(x,ypeor,'ro', color='red', marker='o', label='Peor Caso')
plt.plot(x,yrandom1,'ro', color='blue', marker='o', label='Caso Promedio')
plt.plot(x,yrandom2,'ro', color='blue')
plt.plot(x,yrandom3,'ro', color='blue')

yfunction = []
tfunction = []

a = 50 
for m in range(0,21):
  tfunction.append(0.0000001851*a*a*log(a))
  a += 50 

x= [50,100,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000, 1050]

#sin 'ro' lo plotea como una funcion comun, continua
plt.plot(x,tfunction, color='purple', label='T(n)=k*(n^2*log(n))',linewidth=3)
plt.legend(numpoints=1, loc=2)

#nombre que va en el eje x
plt.xlabel("cantidad de intersecciones entre pasillos")

#nombre que va en el eje y
plt.ylabel("Tiempo(segundos)")

#area = 34

plt.show()
