import numpy as np
import matplotlib.pyplot as plt
from math import log

# y[0..1] = mejoresCasos e=3
# y[2..4] = CasosPromedios e=3
# y[4..5] = CasoPeor e=3

#x = [3, 3, 3, 3, 3, 3]
#numeros del eje x
x = [666,7674,38336,120047,291226,601121,1109816,1888227,3018106,4592034]
#y = [0.000002, 0.000007, 0.000028, 0.000029, 0.000029, 0.000049]

# valores primera funcion
# ymejor = [0.000124, 0.000124, 0.000183, 0.000221, 0.000254, 0.000291, 0.000357, 0.000362, 0.000392, 0.000449]
#[0.66029 ,0.71213,0.75875,1.370972 ]  

#valores segunda funcion
# yrandom = [0.000139, 0.000139,0.000208,0.000284,0.000354,0.000425,0.000495,0.000614,0.000630,0.000729]

#
ypeor = [0.000104,0.001211,0.007707,0.026795,0.070300,0.134302,0.243227,0.410732,0.667897,1.017004]

#'ro' te dice que lo plotee con los numeritos que escribiste, como puntitos en el grafico
# plt.plot(x,ymejor,'ro', color='green')
# plt.plot(x,yrandom,'ro', color='blue')
plt.plot(x,ypeor,'ro', color='red')

# yfunction = []
# tfunction = []

# x = [0,100,200,300,400,500,600,700,800,900,1000]

# for m in range(0,11):
# 	if m == 0:
# 		yfunction.append(0)
# 	else:
# 		# yfunction.append(0.000007*m)
# 		yfunction.append(0.00003599*m*log(m,2))

# for m in range(0,11):
# 	if m == 0:
# 		tfunction.append(0)
# 	else:
# 		# tfunction.append(0.000007*m)
# 		tfunction.append(0.00003*m)


#sin 'ro' lo plotea como una funcion comun, continua
# plt.plot(x,yfunction, color='purple', label='T(n)=c.n.log(n)',linewidth=3)
# plt.plot(x,tfunction, color='darkorange', label ='T(n)=k.n',linewidth=3)
plt.legend()

#nombre que va en el eje x
plt.xlabel("Tamaño de la entrada (cantidad de elementos del arreglo)")

#nombre que va en el eje y
plt.ylabel("Tiempo(segundos)")

#area = 34

plt.show()