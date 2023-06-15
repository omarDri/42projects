while IFS= read -r line
do
	./push_swap $line
	output=$(./push_swap $line | wc -l)
	./push_swap $line | ./checker_Mac $line
	isko=$(./push_swap $line | ./checker_Mac $line)
	if [ "$output" -gt 16 ]; then
		echo "N$output is greater than 16 and the input is $line"
		break
	fi
	if [ "$isko" == "KO" ]; then
		echo "N$output and the input is $line"
		break
	fi
done < permutations.txt