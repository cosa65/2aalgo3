# for ((i=1; c<=1000000; c=c+50))
# do
# 	j=$((i-1))
# 	echo "Generando mejor caso para $i pisos"
# 	./mejorCaso mejor$i $i $j
# done

g++ -std=c++11 mejorCaso.cpp -o mejorCaso
mkdir ../mejorCaso_in

COUNTER=1
while [  $COUNTER -lt 2000 ]; do
	j=$((COUNTER-1))
	echo "Generando mejor caso para $COUNTER pisos"
	./mejorCaso ../mejorCaso_in/mejor$COUNTER $COUNTER $j
	let COUNTER=COUNTER+100
done