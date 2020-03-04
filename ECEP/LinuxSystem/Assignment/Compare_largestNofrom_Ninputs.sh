echo "Enter Numbers you want to compare"
read A
NUM=( $A )
for (( i=0; i< ${#NUM[@]}; i++ ))
do
	if [ ${NUM[0]} -lt ${NUM[$i]} ]
	then
NUM[0]=${NUM[$i]}
fi
done
echo -e "The Greatest Number is:\t${NUM[0]}"





