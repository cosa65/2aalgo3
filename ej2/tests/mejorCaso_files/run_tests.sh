g++ -std=c++11 ej2Timed.cpp -o ej2Timed

for i in $(ls ../mejorCaso_in)
do
	echo "Midiendo tiempos para $i"
	./ej2Timed ../mejorCaso_in/$i ../mejorCaso_out/$i
done