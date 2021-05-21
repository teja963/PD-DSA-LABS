name=$1
prob=$2
if [ $(ls $name 2> log.txt) ]; then
	gcc $name -o a.out 2> log.txt
	var=$(grep "compilation terminated." log.txt)
      	if [ "$var" = "" ]; then	
	for i in {1..5}
	do
	start=$(date +%s.%N)
	./a.out <p${prob}/inp/inp${i}.txt 1> out.txt
	       	end=$(date +%s.%N)
	myvar=$(diff -ZB out.txt p${prob}/exp/exp${i}.txt)
	diff=$(echo "$end - $start" | bc)	
	if [ -z "$myvar" ]; then
		echo "TEST CASE ${i} PASSED, Time taken = ${diff} s"
	else
		echo "WRONG ANSWER IN TEST${i}"
		echo -e "Given input:"
		cat p${prob}/inp/inp${i}.txt
		echo "Expected Output:"
		cat p${prob}/exp/exp${i}.txt
		echo "Your Output:"
		cat out.txt
		break

	fi
	done
	else
		echo "CE"
	fi
else 
	echo "File not there"
fi


