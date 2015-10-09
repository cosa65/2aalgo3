# for ((i=1; c<=1000000; c=c+50))
# do
# 	j=$((i-1))
# 	echo "Generando peor caso para $i pisos"
# 	./mejorCaso mejor$i $i $j
# done

g++ -std=c++11 peorCaso.cpp -o peorCaso
mkdir ../peorCaso_in

COUNTER=1
while [  $COUNTER -lt 51 ]; do
	j=$((COUNTER-1))
	echo "Generando peor caso para $COUNTER pisos"
	./peorCaso ../peorCaso_in/peor$COUNTER $COUNTER $j
	let COUNTER=COUNTER+5
done