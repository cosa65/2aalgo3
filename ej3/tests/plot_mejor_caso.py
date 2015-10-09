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

# valores primera funcion
ymejor = []
f = open('tiempos_mejor_caso.txt', 'r')
for line in f:
  ymejor.append(float(line[:-1]))

mejor_caso = plt.plot(x,ymejor,'ro', color='green', marker='o', label='Mejor Caso')

tfunction = []

a = 50 
for m in range(0,21):
  tfunction.append(0.0000002051*a*log(a))
  a += 50 

x= [50,100,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000, 1050]

#sin 'ro' lo plotea como una funcion comun, continua
plt.plot(x,tfunction, color='purple', label='T(n)=k*(n*log(n))',linewidth=3)
plt.legend(numpoints=1,loc=2)

#nombre que va en el eje x
plt.xlabel("cantidad de intersecciones entre pasillos")

#nombre que va en el eje y
plt.ylabel("Tiempo(segundos)")

#area = 34

plt.show()
