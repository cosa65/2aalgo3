import numpy as np
import matplotlib.pyplot as plt
from math import log


#numeros del eje x
x= [50,100,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000]

# valores primera funcion
ymejor = []
f = open('tiempos_mejor_caso.txt', 'r')
for line in f:
  ymejor.append(float(line[:-1]))

f = open('tiempos_caso_promedio.txt', 'r')
yrandom1 = []
yrandom2 = []
yrandom3 = []
for i in range(0,20):
    yrandom1.append(float(f.readline()[:-1]))
    yrandom2.append(float(f.readline()[:-1]))
    yrandom3.append(float(f.readline()[:-1]))


ypeor = []
f = open('tiempos_peor_caso.txt', 'r')
for line in f:
  ypeor.append(float(line[:-1]))

print len(ymejor)
print len(yrandom1)
print len(yrandom2)
print len(yrandom3)
print len(ypeor)
print len(x)

mejor_caso = plt.plot(x,ymejor,'ro', color='green', marker='o', label='Mejor Caso')
peor_caso = plt.plot(x,ypeor,'ro', color='red', marker='o', label='Peor Caso')
caso_random = plt.plot(x,yrandom1,'ro', color='blue', marker='o', label= 'Caso Random')
plt.plot(x,yrandom2,'ro', color='blue')
plt.plot(x,yrandom3,'ro', color='blue')


tfunction = []

a = 50 
for m in range(0,21):
  tfunction.append(0.000000007051*a*a)
  a += 50 

x= [50,100,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000, 1050]

#sin 'ro' lo plotea como una funcion comun, continua
plt.plot(x,tfunction, color='purple', label='T(n)=k*n^2',linewidth=3)
plt.legend(numpoints=1,loc=2)

#nombre que va en el eje x
plt.xlabel("cantidad de intersecciones entre pasillos")

#nombre que va en el eje y
plt.ylabel("Tiempo(segundos)")

#area = 34

plt.show()
