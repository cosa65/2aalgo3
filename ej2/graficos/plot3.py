import numpy as np
import matplotlib.pyplot as plt
from math import log

# y[0..1] = mejoresCasos e=3
# y[2..4] = CasosPromedios e=3
# y[4..5] = CasoPeor e=3

#x = [3, 3, 3, 3, 3, 3]
#numeros del eje x
x = [10,20,30,40,50,60,70,80,90,100,200,300,400,500,600,700,800,900,1000]
#y = [0.000002, 0.000007, 0.000028, 0.000029, 0.000029, 0.000049]

# valores primera funcion
ymejor = [0.000009,0.000012,0.000017,0.000021,0.000025,0.000030,0.000034,0.000040,0.000042, 0.000050, 0.000124, 0.000183, 0.000221, 0.000254, 0.000291, 0.000357, 0.000362, 0.000392, 0.000449]
#[0.66029 ,0.71213,0.75875,1.370972 ]  

#valores segunda funcion
yrandom = [0.000012,0.000015,0.000021,0.000030,0.000039,0.000044,0.000050,0.000057,0.000065,0.000070,0.000139,0.000208,0.000284,0.000354,0.000425,0.000495,0.000614,0.000630,0.000729]

#
ypeor = [0.000011,0.000016,0.000023,0.000031,0.000039,0.000046,0.000054,0.000061,0.000069,0.000077,0.000161,0.000238,0.000323,0.000388,0.000491,0.000584,0.000693,0.000776,0.000840]

#'ro' te dice que lo plotee con los numeritos que escribiste, como puntitos en el grafico
plt.plot(x,ypeor,'ro', color='red', label='Peor Caso')
plt.plot(x,yrandom,'ro', color='blue', label='Caso aleatorio')
plt.plot(x,ymejor,'ro', color='green', label='Mejor Caso')
plt.legend()


yfunction = []

x = [0,10,20,30,40,50,60,70,80,90,100,200,300,400,500,600,700,800,900,1000]

for m in range(0,20):
	if m == 0:
		yfunction.append(0)
	else:
		# yfunction.append(0.000007*m)
		yfunction.append(0.000007*m*log(m,2))



#sin 'ro' lo plotea como una funcion comun, continua
# plt.plot(x,yfunction, color='red')

#nombre que va en el eje x
plt.xlabel("Tamaño de la entrada (cantidad de elementos del arreglo)")

#nombre que va en el eje y
plt.ylabel("Tiempo(segundos)")

#area = 34

plt.show()