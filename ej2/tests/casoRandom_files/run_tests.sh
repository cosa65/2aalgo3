g++ -std=c++11 ej2Timed.cpp -o ej2Timed
mkdir ../casoRandom_out

for i in $(ls ../casoRandom_in)
do
	echo "Midiendo tiempos para $i"
	./ej2Timed ../casoRandom_in/$i ../casoRandom_out/$i
done