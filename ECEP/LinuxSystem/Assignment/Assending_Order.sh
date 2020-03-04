echo "Enter the Number Series"
read A
echo "Ascending order is"
NUM=( $A )
for (( i=0; i< ${#NUM[@]}; i++ ))
do
	for (( j=$i+1; j<${#NUM[@]}; j++ ))
do 
	if [ ${NUM[$i]} -gt ${NUM[$j]} ]
	then 
		NEXT=${NUM[$i]}
		NUM[$i]=${NUM[$j]}
		NUM[$j]=${NEXT}
		
	fi
done
echo -e "\t${NUM[$i]}"
done
echo "Descending order is"
for (( i=0; i< ${#NUM[@]}; i++ ))
do
	for (( j=$i+1; j<${#NUM[@]}; j++ ))
do 
	if [ ${NUM[$i]} -lt ${NUM[$j]} ]
	then 
		NEXT=${NUM[$i]}
		NUM[$i]=${NUM[$j]}
		NUM[$j]=${NEXT}
		
	fi
done
echo -e "\t${NUM[$i]}"
done




