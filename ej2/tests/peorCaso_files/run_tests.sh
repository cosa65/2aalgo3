g++ -std=c++11 ej2Timed.cpp -o ej2Timed

for i in $(ls ../peorCaso_in)
do
	echo "Midiendo tiempos para $i"
	./ej2Timed ../peorCaso_in/$i ../peorCaso_out/$i
done