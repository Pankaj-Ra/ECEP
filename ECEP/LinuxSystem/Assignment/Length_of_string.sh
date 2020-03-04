echo "Enter various string"
read S
LENGTH=( $S )
echo "Length of strings are"
for (( i=0; i< ${#LENGTH[@]}; i++ ))
do
	
	echo -e "\t${LENGTH[$i]}=${#LENGTH[$i]}"
done
