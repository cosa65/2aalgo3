import numpy as np
import matplotlib.pyplot as plt
from math import log

# y[0..1] = mejoresCasos e=3
# y[2..4] = CasosPromedios e=3
# y[4..5] = CasoPeor e=3

#x = [3, 3, 3, 3, 3, 3]
#numeros del eje x
x_chico = [10,20,30,40,50,60,70,80,90,100]
x_grande = [100,200,300,400,500,600,700,800,900,1000]
#y = [0.000002, 0.000007, 0.000028, 0.000029, 0.000029, 0.000049]

# valores primera funcion
ymejor_chico = [0.0000009, 0.000002 , 0.000003 , 0.000005 , 0.000008 , 0.000011 ,
          0.000015 , 0.000019 , 0.000023 , 0.000028 ]# a partir de aca termina el 100
ymejor_grande = [0.000028, 0.000111 , 0.000245 , 0.000446 , 0.000701 , 0.001025 ,
          0.001433 , 0.001958 , 0.002599 , 0.003645] 
#[0.66029 ,0.71213,0.75875,1.370972 ]  

#valores segunda funcion
f = open('tiempos_caso_promedio_leibles.txt', 'r')
yrandom1_chico = []
yrandom2_chico = []
yrandom3_chico = []
yrandom1_grande = [0.00040]
yrandom2_grande = [0.00041]
yrandom3_grande = [0.00042]
for i in range(0,19):
  if i < 10: 
    yrandom1_chico.append(float(f.readline()[:-1]))
    yrandom2_chico.append(float(f.readline()[:-1]))
    yrandom3_chico.append(float(f.readline()[:-1]))
  else:
    yrandom1_grande.append(float(f.readline()[:-1]))
    yrandom2_grande.append(float(f.readline()[:-1]))
    yrandom3_grande.append(float(f.readline()[:-1]))
#yrandom1 = [0.000139, 0.000139,0.000208,0.000284,0.000354,0.000425,0.000495,0.000614,0.000630,0.000729]
#yrandom2 = [0.000139, 0.000139,0.000208,0.000284,0.000354,0.000425,0.000495,0.000614,0.000630,0.000729]
#yrandom2 = [0.000139, 0.000139,0.000208,0.000284,0.000354,0.000425,0.000495,0.000614,0.000630,0.000729]

ypeor_chico = []
ypeor_grande = [0.000070]
f = open('tiempos_peor_caso_leibles.txt', 'r')
for i in range(0,19):
  if i < 10: 
    ypeor_chico.append(float(f.readline()[:-1]))  
  else:
    ypeor_grande.append(float(f.readline()[:-1]))  

#ypeor = [0.000161,0.000161,0.000238,0.000323,0.000388,0.000491,0.000584,0.000693,0.000776,0.000840]

#'ro' te dice que lo plotee con los numeritos que escribiste, como puntitos en el grafico
print len(ymejor_chico)
print len(yrandom1_chico)
print len(yrandom2_chico)
print len(yrandom3_chico)
print len(ypeor_chico)
print len(x_chico)
plt.plot(x_chico,ymejor_chico,'ro', color='green')
plt.plot(x_chico,ypeor_chico,'ro', color='red')
plt.plot(x_chico,yrandom1_chico,'ro', color='blue')
plt.plot(x_chico,yrandom2_chico,'ro', color='blue')
plt.plot(x_chico,yrandom3_chico,'ro', color='blue')

yfunction = []
tfunction = []

a = 10
for m in range(0,11):
  if m == 0:
    yfunction.append(0)
  else:
		# yfunction.append(0.000007*m)
    yfunction.append(0.00000003421*a*a)
    a += 10 

x_chico = [10,20,30,40,50,60,70,80,90,100, 110]

#sin 'ro' lo plotea como una funcion comun, continua
plt.plot(x_chico,yfunction, color='purple', label='T(n)=k*(n^2)',linewidth=3)
plt.legend()

#nombre que va en el eje x
plt.xlabel("Tamano de la entrada (cantidad de pisos)")

#nombre que va en el eje y
plt.ylabel("Tiempo(segundos)")

#area = 34

plt.show()
